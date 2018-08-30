#include "Player.h"



Player::Player(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str, Key l, Key r, Key u, Key dow, Key lshift)
    :
        Ship(p, d, c, s, str),
        left(l),
        right(r),
        up(u),
        down(dow),
        shift(lshift)

{
    //ctor
    this->hp = 3;

}


void Player::setSpeed(long double s) {
    speed = s;
}


void Player::move() {

    long double
        screenRight = static_cast<long double>(jgl::getWindowSize().x())  / 2.L,
        screenLeft = screenRight * -1.L,
        screenTop = (static_cast<long double>(jgl::getWindowSize().y())   / 2.L) * -1.L,
        screenBottom = screenTop * -1.L
    ;
        if(jgl::keyPressed(shift)) {
            speed = 4;
        } else {
            speed = 8;
        }

        if(jgl::keyPressed(left) && pos.x() >  screenLeft + 20) {
            pos.x() -= speed;
        }
        if(jgl::keyPressed(right) && pos.x() < screenRight - 20){
            pos.x() += speed;
        }

        //DONE
        if(jgl::keyPressed(up) && pos.y() > screenTop + 20){
            pos.y() -= speed;

        }
        if(jgl::keyPressed(down) && pos.y() < screenBottom - 20){
            pos.y() += speed;
        }
        shape->setPosition(pos);
    }



Player::~Player()
{

}
