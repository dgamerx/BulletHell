#include "Wiindow.h"

#include "Player.h"
#include "InGame.h"
#include "InMenu.h"

Window *win;

Window *getWindow() {
    return win;
}

void createWindow() {
    win = new Window();
}
void deleteWindow() {
    delete win;
}

Window::Window()
{
    setGameState(InMenu::getInstance());
}

void Window::eventHandler(jgl::Event ev) {
    gs->eventHandler(ev);
}

void Window::errorHandler(uint16_t id, const char *str) {
    jutil::out << id << ": " << str << jutil::endl;
}


GameState *Window::getGameState() {
    return gs;
}

void Window::setGameState(GameState *g) {
    gs = g;
}

bool Window::update() {

    gs->update();

    return true;

}
Window::~Window()
{
    //dtor
}
