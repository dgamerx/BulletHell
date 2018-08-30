#ifndef ENEMY_H
#define ENEMY_H

#include "Ship.h"

class Enemy: public Ship
{
    public:
        Enemy(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str);
        virtual ~Enemy();

    virtual void move() = 0;

   // virtual void setMoveTimer(int) = 0;
   // virtual int getMoveTimer() = 0;
    virtual void abilityOne() = 0;
    virtual void abilityTwo() = 0;
    virtual void abilityThree() = 0;

    virtual void targetPlayer() = 0;

    virtual long double getLPosX() = 0;
    virtual long double getLPosY() = 0;



    virtual void setOffset(jml::Vector2ld) = 0;


    protected:
        int phase;
        long double lPosX;
        long double lPosY;
        jml::Vector2ld offSet;
    private:



};

#endif // ENEMY_H
