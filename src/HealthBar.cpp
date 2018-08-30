#include "HealthBar.h"
#include "GameState.h"

HealthBar::HealthBar(pVar p, dVar d, jgl::Color c,jgl::Object* s, jutil::String str)
    :
        Sprite(p, d, c, s, str)
{
    //ctor
}

void HealthBar::decreaseQuadSize(int maxHP, int multiBar) {
    shape->setSize({maxHP * multiBar, shape->getSize().y()});
    shape->draw();
}



HealthBar::~HealthBar()
{
    //dtor
}
