#include "Enemy.h"
#include "GameState.h"
#include "InGame.h"
#include <cmath>

Enemy::Enemy(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str)
    :
        Ship(p, d, c, s, str)
{
    this->hp = 300;
    this->phase = 0;
}


long double Enemy::getLPosX(){
    return lPosX;
}
long double Enemy::getLPosY(){
    return lPosY;
}


void Enemy::setOffset(jml::Vector2ld v) {
    offSet = v;
}



void Enemy::abilityOne() {
    long long est = InGame::getInstance()->getLevel()->getFrameCounter();
    long long interval = 300;
    long long magazine = 10;

    if(est >= interval) {
        for(long long i = 0; i < magazine; ++i) {
            if((est - i ) %  interval == 0) {
                Bullet::enemyShoot(offSet);
            }
        }
    }
}


void Enemy::abilityTwo() {
    long long est = InGame::getInstance()->getLevel()->getFrameCounter();
    long long interval = 1;
    long double speed = 1;
    if(est >= interval) {
        if(est % interval == 0) {
            Bullet::enemyShoot({getPos().x() - 50, getPos().y()  - (getShape()->getSize().y() / 2)}, speed);
        }
        else if((est - 5) % interval == 0) {
            Bullet::enemyShoot({getPos().x() - 200, getPos().y()  - (getShape()->getSize().y() / 2)}, speed);
        }
        else if((est - 15) % interval == 0) {
            Bullet::enemyShoot({getPos().x() - 400, getPos().y()  - (getShape()->getSize().y() / 2)}, speed);
        }
        else if((est - 25) % interval == 0) {
            Bullet::enemyShoot({getPos().x() + 50, getPos().y()  - (getShape()->getSize().y() / 2)}, speed);
        }
        else if((est - 35) % interval == 0) {
            Bullet::enemyShoot({getPos().x() + 200, getPos().y()  - (getShape()->getSize().y() / 2)}, speed);
        }
        else if((est - 45) % interval == 0) {
            Bullet::enemyShoot({getPos().x() + 400, getPos().y()  - (getShape()->getSize().y() / 2)},speed);
        }
    }
}


void Enemy::abilityThree() {
    long long est = InGame::getInstance()->getLevel()->getFrameCounter();
    long long interval = 1;
    long double speed = 0.5;
    long double
    screenRight = static_cast<long double>(jgl::getWindowSize().x())  / 2.L,
    screenLeft = screenRight * -1.L,
    screenTop = (static_cast<long double>(jgl::getWindowSize().y())   / 2.L) * -1.L,
    screenBottom = screenTop
    ;

    jutil::RNG
        rY(screenTop, screenBottom),
        rX(screenLeft, screenRight)
    ;

    long double randX = rX.get<long double>();
    long double randY = rY.get<long double>();
    if(est >= interval) {
        if(est % interval == 0) {
            Bullet::enemyShoot({randX, randY}, speed);
        }
        else if((est - 5) % interval == 0) {
            Bullet::enemyShoot({randX, randY}, speed);
        }
        else if((est - 15) % interval == 0) {
            Bullet::enemyShoot({randX, randY}, speed);
        }
        else if((est - 25) % interval == 0) {
            Bullet::enemyShoot({randX, randY}, speed);
        }
        else if((est - 35) % interval == 0) {
            Bullet::enemyShoot({randX, randY}, speed);
        }
        else if((est - 45) % interval == 0) {
            Bullet::enemyShoot({randX, randY}, speed);
        }
    }
}



void Enemy::targetPlayer() {
    long long est = InGame::getInstance()->getLevel()->getFrameCounter();
    if(!InGame::getInstance()->getLevel()->getPlayer()->died()) {
        if(est % 15 == 0){
            Bullet::enemyShoot(offSet);
        }
        abilityOne();
        abilityTwo();
        abilityThree();
    }
        Bullet::enemyLineFire();
}


void Enemy::move() {
    //Get screen edges
    long double
        screenRight = static_cast<long double>(jgl::getWindowSize().x())  / 2.L,
        screenLeft = screenRight * -1.L,
        screenTop = (static_cast<long double>(jgl::getWindowSize().y())   / 2.L) * -1.L,
        screenBottom = screenTop + 200;
    ;

    //Construct rng with screen edges
    jutil::RNG
        rY(screenTop, screenBottom),
        rX(screenLeft, screenRight)
    ;

    long double randX = rX.get<long double>();
    long double randY = rY.get<long double>();

    //Logic based on time elapsed
    if(jml::compare(pos.x(), randX) == JML_LESS) {
        pos.x() += 8;
    }
    if(jml::compare(pos.x(), randX) == JML_GREATER){
        pos.x() -= 8;
    }
    if(jml::compare(pos.y(), randY) == JML_LESS) {
        pos.y() += 8;
    }
    if(jml::compare(pos.y(), randY) == JML_GREATER) {
        pos.y() -= 8;
    }
    shape->setPosition({pos.x(),pos.y()});
    /*if(!Bullet::enemyBullets.empty()) {
        getWindow()->getEnemy()->getShape()->setRotation(jml::Angle(Bullet::enemyBullets.last().getAngle()));
    }*/
    setOffset({getPos().x(),
        getPos().y() - (getShape()->getSize().y() / 2)});
}


Enemy::~Enemy()
{
    //dtor
}
