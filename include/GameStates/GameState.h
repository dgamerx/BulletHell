#ifndef GAMESTATE_H
#define GAMESTATE_H


#include <jgl.h>
#include <LevelsInclude.h>

class GameState
{
    public:
        GameState();
        virtual ~GameState();

        virtual void update() = 0;
        virtual void eventHandler(jgl::Event) = 0;

    protected:

    private:
};





#endif // GAMESTATE_H
