#ifndef INGAME_H
#define INGAME_H

#include "GameState.h"

class InGame : public GameState { //Singleton
    public:
        ~InGame();


        void update() override;
        void eventHandler(jgl::Event) override;

        static InGame *getInstance();
        static void createInstance();

        void setLevel(Level*) override;

        Level *getLevel() override;

    protected:

    private:
        static InGame *instance;
        InGame();
        jgl::LightSource li;

};
#endif // INGAME_H
