#ifndef PLAYOPTION_H
#define PLAYOPTION_H

#include "Options.h"

class PlayOption : public Options
{
    public:
        virtual ~PlayOption();

        void update() override;
        void eventHandler(jgl::Event) override;

        static PlayOption *getInstance();
        static void createInstance();

    protected:

    private:
        static PlayOption *instance;
        PlayOption();
};

#endif // PLAYOPTION_H
