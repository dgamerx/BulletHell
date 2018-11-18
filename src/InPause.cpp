#include "InPause.h"
#include "Wiindow.h"
#include "InGame.h"
/*  PAUSE CLASS*/

InPause *InPause::instance = NULL;

InPause::InPause()

        //pauseFont("C:\\Users\\Dgamerx\\Documents\\2DPlatformer\\arial.ttf", 20),
        //pauseText(pauseFont, "PAUSED", {0,0}, jgl::Color::Black)

{
}

Level *InPause::getLevel() {
    return lv;
}

void InPause::setLevel(Level *lev) {
    lv = lev;
}

void InPause::createInstance() {
    instance = new InPause();
    instance->pause = new jgl::Quad({0,0},{500, 100},jgl::Color::Blue);
    instance->pause->setTexture(".\\src\\PAUSED.png");

}

InPause *InPause::getInstance() {
    if (!instance) createInstance();
        return InPause::instance;
}

/* OVERRIDEN FUNCTIONS*/

void InPause::eventHandler(jgl::Event ev) {
    switch(ev.type){
    case ev.KEY:
        if(ev.code == ev.ESCAPE && ev.action == ev.RELEASE){
            jutil::out << "ESCAPE PRESSED" << jutil::endl;
            jgl::setClearColor(jgl::Color::Black);
            getWindow()->setGameState(InGame::getInstance());

        } else if (ev.code == ev.F1 && ev.action == ev.RELEASE) {

                InGame::getInstance()->getLevel()->resetLevel();
                getWindow()->setGameState(InGame::getInstance());

                Bullet::enemyBullets.clear();
                Bullet::bullets.clear();
                jgl::setClearColor(jgl::Color::Black);
        }
        break;
    }
}


void InPause::update() {

    pause->draw();
    //pauseText.draw();

}
