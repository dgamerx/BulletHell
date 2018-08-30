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

        void setLevel(Level*);



        Level *getLevel();

    protected:

    private:
        static InGame *instance;
        InGame();
        Level *lv;
        jgl::LightSource li;

};
#endif // INGAME_H
