#ifndef INMENU_H
#define INMENU_H

#include "GameState.h"
#include "Options.h"

class InMenu : public GameState
{
    public:
        virtual ~InMenu();
        void update() override;
        void eventHandler(jgl::Event) override;

        static InMenu *getInstance();
        static void createInstance();
        void setLevel(Level*) override;

        Level *getLevel() override;

    protected:
        Options *op;
    private:
        static InMenu *instance;
        InMenu();

};

#endif // INMENU_H
