#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "Sprite.h"

class HealthBar: public Sprite
{
    public:
        HealthBar(pVar p, dVar d, jgl::Color c, jgl::Object* s,jutil::String str);
        virtual ~HealthBar();

        void decreaseQuadSize(int, int = 1);

    protected:

    private:
        unsigned hp;


};

#endif // HEALTHBAR_H
