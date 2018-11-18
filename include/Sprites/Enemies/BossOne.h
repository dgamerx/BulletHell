#ifndef BOSSONE_H
#define BOSSONE_H

#include "Enemy.h"

class BossOne: public Enemy

{
    public:
        BossOne(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str);
        virtual ~BossOne();

    void move() override;


    void abilityOne() override;
    void abilityTwo() override;
    void abilityThree() override;

    void targetPlayer() override;





    void setOffset(jml::Vector2ld) override;


    protected:

    private:



};

#endif // BOSSONE_H
