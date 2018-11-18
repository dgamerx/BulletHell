#include "PlayOption.h"


PlayOption *PlayOption::instance = NULL;

PlayOption::PlayOption()
{
    //ctor
}

void PlayOption::update() {

}

void PlayOption::eventHandler(jgl::Event ev) {

}

PlayOption *PlayOption::getInstance() {
    if (!instance) createInstance();
        return PlayOption::instance;
}

void PlayOption::createInstance() {
    if(!instance) {
        instance = new PlayOption();
    }
}


PlayOption::~PlayOption()
{
    //dtor
}
