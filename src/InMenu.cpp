#include "InMenu.h"
#include "TitleOption.h"




InMenu *InMenu::instance = NULL;

InMenu::InMenu()
{
    //ctor
}



void InMenu::eventHandler(jgl::Event e) {
    op->eventHandler(e);
}

void InMenu::createInstance() {
    instance = new InMenu();
    instance->op = TitleOption::getInstance();

}



InMenu *InMenu::getInstance() {

    if (!instance) createInstance();

    return InMenu::instance;
}


Level *InMenu::getLevel() {
    return lv;
}

void InMenu::setLevel(Level *lev) {
    lv = lev;
}

void InMenu::update() {

    op->update();

}

InMenu::~InMenu()
{
    //dtor
}
