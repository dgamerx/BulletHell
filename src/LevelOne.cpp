#include "LevelOne.h"

Player *LevelOne::getPlayer()  {
    return p;
}
Enemy *LevelOne::getEnemy()  {
    return e;
}

LevelOne::LevelOne()
{

}

LevelOne *LevelOne::instance = NULL;

long long Level::getFrameCounter() {
    return frameCounter;
}


LevelOne *LevelOne::getInstance() {

    if (!instance) createInstance();

    return LevelOne::instance;
}

void LevelOne::deleteLevelData() {
    delete instance->q;
    delete instance->eQ;
    delete instance->p;
    delete instance->e;
    delete instance->enemyHealthBar;
    delete instance->playerHealthBar;
    delete instance->enemyHP;
    delete instance->playerHP;
}

void LevelOne::createLevelData() {
    instance->q = new jgl::Quad({0,0},{25,25},jgl::Color::Blue);
    instance->eQ = new jgl::Quad({0, -710/2},{100,100},jgl::Color::Red);
    instance->p = new Player({0,300},{10,10},jgl::Color::Blue, instance->q, "",  Key::ARROW_LEFT, Key::ARROW_RIGHT, Key::ARROW_UP,Key::ARROW_DOWN, Key::LEFT_SHIFT);
    instance->e = new Enemy({0, -600 / 2},{10,10},jgl::Color::Red, instance->eQ, "");
    instance->enemyHealthBar = new  jgl::Quad({-425, -300},{50, 25}, jgl::Color::Yellow);
    instance->playerHealthBar = new jgl::Quad({-500,300}, {100,25}, jgl::Color::Green);
    instance->enemyHP = new HealthBar({-400, -300},{100, 50}, jgl::Color::Yellow, instance->enemyHealthBar, "");
    instance->playerHP = new HealthBar({-400,300}, {100,50}, jgl::Color::Green, instance->playerHealthBar, "");
    instance->frameCounter = 0;
}

void LevelOne::createInstance() {
    if(!instance) {
        instance = new LevelOne();
        instance->createLevelData();
    }
}

LevelOne::~LevelOne() {
    deleteLevelData();
}


void LevelOne::resetLevel() {
    deleteLevelData();
    createLevelData();
}

void LevelOne::update() {
    if(!e->died()){
        eQ->draw();
        e->move();
        e->targetPlayer();
        enemyHP->decreaseQuadSize(e->getHP());
    } else {
        eQ->scale(0);
    }

    if(!p->died()) {
        int multiplyForLength = 33;
        q->draw();
        p->move();
        playerHP->decreaseQuadSize( p->getHP(), multiplyForLength);
        Bullet::moveBullet();
        if (jgl::keyPressed(jgl::Event::Key::F) && frameCounter % 10 == 0) {
            Bullet::shoot();
        }
    }  else {
        q->scale(0);
    }
    ++frameCounter;
}
