#ifndef WIINDOW_H
#define WIINDOW_H

#include <jgl.h>
#include <GameState.h>

class Window: public jgl::Core {
    public:
        Window();
        virtual ~Window();
        bool update() override; // myCycle
        void eventHandler(jgl::Event) override;
        void errorHandler(uint16_t, const char*) override;

        GameState *getGameState();

        void setGameState(GameState*);


    protected:

    private:
        GameState *gs;

};

Window *getWindow();
void createWindow();
void deleteWindow();

#endif // WIINDOW_H
