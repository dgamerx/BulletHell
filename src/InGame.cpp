#include "InGame.h"
#include "Wiindow.h"
#include "InPause.h"

InGame *InGame::instance = NULL;

InGame::InGame() : li(0, 300, jgl::Color::White)

    /*:
        q({0,0},{25,25},jgl::Color::Blue),
        eQ({0, -710/2},{100,100},jgl::Color::Red),
        p({0,0},{10,10},jgl::Color::Blue, &q, "", Key::ARROW_LEFT, Key::ARROW_RIGHT, Key::ARROW_UP,Key::ARROW_DOWN),
        e({0, -600 / 2},{10,10},jgl::Color::Red, &eQ, "")*/

{
    //InGame::shootTime.start();
}

InGame::~InGame()

{

}


// Key::A, Key::D, Key::W,Key::S

void InGame::createInstance() {
    instance = new InGame();
    instance->lv = LevelOne::getInstance();

}


Level *InGame::getLevel() {
    return lv;
}

void InGame::setLevel(Level *lev) {
    lv = lev;
}

InGame *InGame::getInstance() {

    if (!instance) createInstance();

    return InGame::instance;
}

/* OVERRIDEN FUNCTIONS*/

void InGame::eventHandler(jgl::Event ev) {
    switch(ev.type){
        case ev.MOUSE:
           /* if(ev.code == jgl::Event::Button::LEFT && ev.action == ev.PRESS){
                if (InGame::getInstance()->getLevel()->shootTime.get() > 0.1) {
                    Bullet::shoot();
                    InGame::getInstance()->getLevel()->shootTime.restart();
                }
            }
            break;*/
        case ev.KEY:
            if(ev.code == ev.ESCAPE && ev.action == ev.RELEASE){
                jutil::out << "ESCAPE PRESSED" << jutil::endl;
                getWindow()->setGameState(InPause::getInstance());
                jgl::setClearColor(jgl::Color(100,100,100));

            } else if (ev.code == ev.F && ev.action == ev.RELEASE) {
                //jutil::out << Bullet::bullets.size() << jutil::endl;
                //Bullet::shoot();
            }
            break;
    }

}


void InGame::update() {
    // levels
    li.position = lv->getPlayer()->getPos();
    jgl::useLightSource(li);
    lv->update();

}

