#ifndef SHIP_H
#define SHIP_H

#include "Sprite.h"

class Ship: public Sprite
{
    public:
        Ship(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str);
        virtual ~Ship();
        /*
        *   GETTERS
        */
        int getHP() const;


        /*
        * SETTERS
        */
        void setHP(int);
        /*
        * CLASS FUNCTIONS
        */

        virtual void move() = 0;
        bool died();

    protected:
        int hp;

    private:

};

#endif // SHIP_H
