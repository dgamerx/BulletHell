#include "BossOne.h"
#include "GameState.h"
#include "InGame.h"
#include <cmath>

BossOne::BossOne(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str)
    :
        Enemy(p, d, c, s, str)
{
    this->hp = 150;
    this->phase = 0;
}




void BossOne::setOffset(jml::Vector2ld v) {
    offSet = v;
}



void BossOne::abilityOne() { // persistent fire
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


void BossOne::abilityTwo() { // quick shotgun burst
    long long est = InGame::getInstance()->getLevel()->getFrameCounter();
    long long interval = 400;
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


void BossOne::abilityThree() { // mine spawns
    long long est = InGame::getInstance()->getLevel()->getFrameCounter();
    long long interval = 200;
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



void BossOne::targetPlayer() {
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


void BossOne::move() {
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
    /*if(!Bullet::BossOneBullets.empty()) {
        getWindow()->getBossOne()->getShape()->setRotation(jml::Angle(Bullet::BossOneBullets.last().getAngle()));
    }*/
    setOffset({getPos().x(),
        getPos().y() - (getShape()->getSize().y() / 2)});
}


BossOne::~BossOne()
{


}
