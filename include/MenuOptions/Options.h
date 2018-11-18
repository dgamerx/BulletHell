#ifndef OPTIONS_H
#define OPTIONS_H

#include "jgl.h"

class Options
{
    public:
        Options();
        virtual ~Options();

        virtual void update() = 0;
        virtual void eventHandler(jgl::Event) = 0;

    protected:
    private:
};

#endif // OPTIONS_H
