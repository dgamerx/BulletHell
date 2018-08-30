#include "Enemy.h"


Enemy::Enemy(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str)
    :
        Ship(p, d, c, s, str)
{
}




Enemy::~Enemy()
{
    //dtor
}
