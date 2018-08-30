#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"


typedef jml::Vector<long double, 2> pVar;
typedef jml::Vector<unsigned int, 2> dVar;
typedef jgl::Event::Key Key;

class Player: public Ship
{
    public:

        using Ship::move;

        Player(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str, Key l, Key r, Key u, Key down, Key shift);
        virtual ~Player();

        void setSpeed(long double);


        void move() override;

    protected:

    private:
        jgl::Event::Key left, right, down, up, shift;
        long double speed;

};

#endif // PLAYER_H
