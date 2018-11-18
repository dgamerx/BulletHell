#include "Wiindow.h"

/**
*  --CHALLENGE: Move bullets towards cursor //jgl::getMouseInWorld()
*  ----------------------------------------
*  --CREATE ENEMIES HP, --CAN DIE
*  --CREATE BULLETS & BULLET SHOOTING STYLE
*  -- ENEMY SHOOTS BULLETTS
*  --MAKE BULLET PATH SMOOTH
*  --MAKE GAME STATES
*  MAKE HEALTH BARS -- done but make better object orientated design (do it over again stupid)
*   make it so you die if you touch enemy boss
*
*   ENEMY  ABILITYS / SHOOTING STYLES TWO SO FAR IN PROGESS -
*   MOVE SHOOTING FUNCTION TO PROPER CLASSES FROM BULLET CLASS
*
*   --LEVELS
*   MAKE ENEMY CLASS INHERIATBLE STYLE
*   CREATE LEVELS WITH UNIQUE BOSSES AND SHIT
*   CREATE BULLETS THAT SHOOT IN PATERNS
*
*
*   MATH:
*    1. ALGEBRA
*    2. LINEAR ALGEBRA
*    3. PRE-CALC
*    4. TRIG
*
*   ADD 2 PLAYER MODE
*   POWERUPS
*   CUSTOMIZABLE SHIPS
*   CUSTOM ABILITIES -- MAYBE CREATE YOUR OWN ABILITY
*
*/

using namespace jml::literals;

#include <windows.h>


int main() {

    HWND consoleWindow = GetConsoleWindow();

	SetWindowPos( consoleWindow, 0, 20, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );

    jutil::String title = "Test";
    jgl::init(1200, title);
    jgl::setLightingMode(JGL_LIGHTING_NONE);
    jgl::setClearColor(jgl::Color::Black);
    jgl::setMouseVisible(true);

    jgl::setFrameTimeLimit(16);
    createWindow();

    jgl::begin(*getWindow()); // starts gameloop

    deleteWindow();
	return jgl::end(0);
}



/*
class MainCore : public jgl::Core {
public:
    MainCore() :
        q({(jgl::getWindowSize().x() / 2.0) - 51, (jgl::getWindowSize().y() / 2.0) - 51}, {20, 20}, jgl::Color::Yellow),
        line({-1.f * jgl::getWindowSize().x() / 2.f, -1.f * jgl::getWindowSize().y() / 2.f}, {(jgl::getWindowSize().x() / 2.0), (jgl::getWindowSize().y() / 2.0)}, jgl::Color::Cyan),
        l(-200, 10000, jgl::Color::Cyan),
        l2(200, 10000, jgl::Color::Magenta),
        l3(0, 10000, jgl::Color::Yellow),
        tri({0,0},{50,50},jgl::Color::Blue, jgl::Triangle::Type::RIGHT),
        mPoly(3,{10,-20},{100,100},jgl::Color::Green)
        {

        }

    bool update() override {
        jgl::useLightSource(l);
        jgl::useLightSource(l2);
        q.setPosition(jgl::getMouseInWorld());
        q.rotate(8_degs);
        tri.move({1,1});
        jgl::render(mPoly);
        jgl::render(line);
        jgl::render(tri);
        jgl::render(q);
        return true;
    }

private:
    jgl::Quad q;
    jgl::Line line;
    jgl::Poly mPoly;
    jgl::Triangle tri;
    jutil::Timer timer;
    jgl::LightSource l, l2, l3;
    jutil::Queue<long long> tq;
};

int main() {

    */
