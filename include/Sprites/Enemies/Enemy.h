#ifndef ENEMY_H
#define ENEMY_H

#include "Ship.h"

class Enemy: public Ship
{
    public:
        Enemy(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str);
        virtual ~Enemy();

    void move() override;

    void setMoveTimer(int);
    int getMoveTimer();
    void abilityOne();
    void abilityTwo();
    void abilityThree();

    void targetPlayer();

    long double getLPosX();
    long double getLPosY();



    void setOffset(jml::Vector2ld);


    protected:

    private:
        int phase;
        long double lPosX;
        long double lPosY;
        jml::Vector2ld offSet;


};

#endif // ENEMY_H
