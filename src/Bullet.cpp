#include "Bullet.h"
#include "GameState.h"
#include "InGame.h"


using namespace jml::literals;

Bullet::Bullet(pVar p, dVar d, jgl::Color c, jutil::String str)
    :
        Sprite(p, d, c, &bQ, str),
        bQ(p,d,c)
        //p()
{
}

jutil::Queue<Bullet> Bullet::bullets;
jutil::Queue<Bullet> Bullet::enemyBullets;

bool Bullet::operator==(Bullet b) {
    if(&(this->bQ) == &(b.bQ)){
        return true;
    }
    return false;

}

void Bullet::shoot() {
    jml::Vector2ld pPos = InGame::getInstance()->getLevel()->getPlayer()->getShape()->getPosition();
    jml::Vector2ld ePos = jgl::getMouseInWorld();

    bullets.insert(Bullet({
        InGame::getInstance()->getLevel()->getPlayer()->getPos().x(),
        InGame::getInstance()->getLevel()->getPlayer()->getPos().y() - (InGame::getInstance()->getLevel()->getPlayer()->getShape()->getSize().y() / 2)},
        {10, 10}, jgl::Color::Blue, ""));

}

void Bullet::enemyShoot(jml::Vector2ld bPos, long double vel) {
    jml::Vector2ld pPos = InGame::getInstance()->getLevel()->getPlayer()->getShape()->getPosition();
    // give me the mags for each pos
    /*long double pMag = pPos.magnitude();
    long double eMag = ePos.magnitude();
    long double cosineAngle = (pPos * ePos) / (pMag * eMag);
    jml::Angle angle(jml::acos(cosineAngle));*/




    enemyBullets.insert(Bullet(bPos,{10, 10}, jgl::Color::Red, ""));
        enemyBullets.last().angle = jml::Angle((bPos * -1) + pPos);
        enemyBullets.last().bQ.setRotation(enemyBullets.last().angle + jml::Angle(JML_PIO2));
        enemyBullets.last().velocity = vel;
}



bool Bullet::collision(Bullet *b) {

    jml::Vector2ld enemyPos = InGame::getInstance()->getLevel()->getEnemy()->getPos();

    long double
        enemyRight  = enemyPos.y() + InGame::getInstance()->getLevel()->getEnemy()->getShape()->getSize().y() / 2.L,
        enemyLeft   = enemyPos.y() - InGame::getInstance()->getLevel()->getEnemy()->getShape()->getSize().y() / 2.L,
        enemyBottom = enemyPos.x() + InGame::getInstance()->getLevel()->getEnemy()->getShape()->getSize().x() / 2.L,
        enemyTop    = enemyPos.x() - InGame::getInstance()->getLevel()->getEnemy()->getShape()->getSize().x() / 2.L
    ;

    bool
        edgeTestRight  = b->bQ.getPosition().y() < enemyRight,
        edgeTestLeft   = b->bQ.getPosition().y() > enemyLeft,
        edgeTestTop    = b->bQ.getPosition().x() > enemyTop,
        edgeTestBottom = b->bQ.getPosition().x() < enemyBottom
    ;

    if(edgeTestBottom && edgeTestTop && edgeTestRight && edgeTestLeft) {
        InGame::getInstance()->getLevel()->getEnemy()->setHP(InGame::getInstance()->getLevel()->getEnemy()->getHP() - 1);
       // jutil::out << InGame::getInstance()->getLevel()->getEnemy()->getHP() << "hp" << jutil::endl;
        bullets.erase(b);
        //jutil::out << "hit detected" << jutil::endl;
        return true;
    }
    return false;
}


bool Bullet::playerCollision(Bullet *b) {

    jml::Vector2ld playerPos = InGame::getInstance()->getLevel()->getPlayer()->getPos();

    long double
        playerRight  = playerPos.y() + InGame::getInstance()->getLevel()->getPlayer()->getShape()->getSize().y() / 2.L,
        playerLeft   = playerPos.y() - InGame::getInstance()->getLevel()->getPlayer()->getShape()->getSize().y() / 2.L,
        playerBottom = playerPos.x() + InGame::getInstance()->getLevel()->getPlayer()->getShape()->getSize().x() / 2.L,
        playerTop    = playerPos.x() - InGame::getInstance()->getLevel()->getPlayer()->getShape()->getSize().x() / 2.L
    ;

    bool
        edgeTestRight  = b->bQ.getPosition().y() < playerRight - 5,
        edgeTestLeft   = b->bQ.getPosition().y() > playerLeft + 5,
        edgeTestTop    = b->bQ.getPosition().x() > playerTop + 5,
        edgeTestBottom = b->bQ.getPosition().x() < playerBottom - 5
    ;

    if(edgeTestBottom && edgeTestTop && edgeTestRight && edgeTestLeft) {
        InGame::getInstance()->getLevel()->getPlayer()->setHP(InGame::getInstance()->getLevel()->getPlayer()->getHP() - 1);
       // jutil::out << InGame::getInstance()->getLevel()->getPlayer()->getHP() << jutil::endl;
        enemyBullets.erase(b);
        //jutil::out << "hit detected player" << jutil::endl;
        return true;
    }
    return false;
}

void Bullet::moveBullet()  {
    for(Bullet *b = bullets.begin(); b != bullets.end();){
        if (!collision(b)) {
            if(b->bQ.getPosition().y() > static_cast<int>(jgl::getWindowSize().y() / 2) * -1 &&
               b->bQ.getPosition().y() < static_cast<int>(jgl::getWindowSize().y() / 2)){

                jml::Vector2ld mVec = {jml::cos(b->pAngle), jml::sin(b->pAngle)};
                //jutil::out << "HIT DETECTED" << jutil::endl;
                b->bQ.move({0, -PLAYER_BULLET_VELOCITY});
                b->bQ.draw();
                ++b;
            }
            else {
                bullets.erase(b);
            }
        }
    }
}


jml::Angle Bullet::getAngle() {
    return angle;
}


void Bullet::enemyLineFire() {
    long double
        screenRight = static_cast<long double>(jgl::getWindowSize().x())  / 2.L,
        screenLeft = screenRight * -1.L,
        screenTop = (static_cast<long double>(jgl::getWindowSize().y())   / 2.L) * -1.L,
        screenBottom = screenTop * -1.L
    ;
    for(Bullet *b = enemyBullets.begin(); b != enemyBullets.end();) {
        if(!playerCollision(b)) {
            if(b->bQ.getPosition().x() > screenLeft && b->bQ.getPosition().x() < screenRight
               && b->bQ.getPosition().y() > screenTop
               && b->bQ.getPosition().y() < screenBottom){


                b->bQ.move(jml::Angle::vector(b->angle) * b->velocity);
                // draw and add to queue
                b->bQ.draw();
                ++b;
            } else {
                enemyBullets.erase(b);
            }
        }
    }
}


Bullet::~Bullet()
{
    //dtor
}
