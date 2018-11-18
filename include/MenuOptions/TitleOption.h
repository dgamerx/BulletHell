#ifndef TitleOption_H
#define TitleOption_H

#include "Options.h"

class TitleOption : public Options
{
    public:
        virtual ~TitleOption();

        void update() override;
        void eventHandler(jgl::Event) override;

        static TitleOption *getInstance();
        static void createInstance();

        void createTitleScreen();
        void deleteTitleScreen();
        //void playButtonAction();

    protected:
        jgl::Quad *menuTitle;
        jgl::Quad *play;
    private:
        static TitleOption *instance;
        TitleOption();

};

#endif // TitleOption_H
