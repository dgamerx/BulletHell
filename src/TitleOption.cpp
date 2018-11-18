#include "TitleOption.h"
#include "Wiindow.h"
#include "InGame.h"

TitleOption *TitleOption::instance = NULL;

TitleOption::TitleOption()
{
    //ctor
}

void TitleOption::update() {
    instance->play->draw();
    instance->menuTitle->draw();
}

void TitleOption::eventHandler(jgl::Event e) {
    switch(e.type) {
            case jgl::Event::MOUSE: {
                switch (e.action) {
                    case jgl::Event::PRESS: {
                        switch (e.code) {
                            case jgl::Event::LEFT: {
                                jutil::out << "Left mosue button pressed." << jutil::endl;
                                break;
                            }
                            case jgl::Event::RIGHT: {
                                jutil::out << "Right mosue button pressed." << jutil::endl;
                                break;
                            }
                        }
                        break;
                    }
                    case jgl::Event::RELEASE: {
                        switch (e.code) {
                            case jgl::Event::LEFT: {
                                jutil::out << "Left mosue button released." << jutil::endl;
                                if(jgl::getMouseInWorld().x() > instance->play->getPosition().x() - instance->play->getSize().x()/2.0 &&
                                   jgl::getMouseInWorld().x() < instance->play->getPosition().x() + instance->play->getSize().x()/2.0 &&
                                   jgl::getMouseInWorld().y() > instance->play->getPosition().y() - instance->play->getSize().y()/2.0 &&
                                   jgl::getMouseInWorld().y() < instance->play->getPosition().y() + instance->play->getSize().x()/2.0){
                                    getWindow()->setGameState(InGame::getInstance());
                                    jgl::setClearColor(jgl::Color(0,0,0));
                                }


                                break;
                            }
                            case jgl::Event::RIGHT: {
                                jutil::out << "Right mosue button released." << jutil::endl;
                                break;
                            }
                        }
                    }
                }
            }
        }
}

void TitleOption::createTitleScreen() {
    jgl::setClearColor(jgl::Color::Magenta);
    instance->menuTitle = new jgl::Quad({0,-250},{688, 111},jgl::Color::Yellow);
    instance->menuTitle->setTexture(".\\src\\BulletHell.png");
    instance->play = new jgl::Quad({0,0}, {113,59});
    instance->play->setTexture(".\\src\\PLAY.png");

}

void TitleOption::deleteTitleScreen() {
    delete instance->menuTitle;
    delete instance->play;
}

TitleOption *TitleOption::getInstance() {
    if (!instance) createInstance();
        return TitleOption::instance;
}

void TitleOption::createInstance() {
    if(!instance) {
        instance = new TitleOption();
        instance->createTitleScreen();
    }
}


TitleOption::~TitleOption()
{
    //dtor
    deleteTitleScreen();

}
