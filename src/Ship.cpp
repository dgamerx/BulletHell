#include "Ship.h"

Ship::Ship(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str)
    :
        Sprite(p, d, c, s, str)

{
    //ctor
}


/*
*   GETTERS
*/
int Ship::getHP() const {
    return hp;
}


/*
* SETTERS
*/
void Ship::setHP(int h) {
    hp = h;
}

/*
* CLASS FUNCTIONS
*/
bool Ship::died() {
    return (hp <= 0);
}

Ship::~Ship()
{
    //dtor
}
