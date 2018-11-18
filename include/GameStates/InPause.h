#ifndef INPAUSE_H
#define INPAUSE_H

#include "GameState.h"

class InPause : public GameState {
    public:
        void update() override;
        void eventHandler(jgl::Event) override;

        static InPause *getInstance();
        static void createInstance();

        Level *getLevel() override;
        void setLevel(Level*) override;

    protected:
        jgl::Quad *pause;

    private:
        static InPause *instance;
        //jgl::Text pauseText;
       // jgl::Font pauseFont;
        InPause();
};

#endif // INPAUSE_H
