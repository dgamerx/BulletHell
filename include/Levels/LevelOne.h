#ifndef LEVELONE_H
#define LEVELONE_H

#include "Level.h"

class LevelOne : public Level {
    public:

        virtual ~LevelOne();

        Player *getPlayer() override;
        Enemy *getEnemy() override;
        void resetLevel() override;


        void update() override;
        void deleteLevelData() override;
        void createLevelData() override;


        static LevelOne *getInstance();
        static void createInstance();



    protected:
        jgl::Quad *q;
        jgl::Quad *eQ;
        jgl::Quad *enemyHealthBar;
        jgl::Quad *playerHealthBar;
    private:
        static LevelOne *instance;
        LevelOne();
        Player *p;
        Enemy *e;
        HealthBar *enemyHP;
        HealthBar *playerHP;


};

#endif // LEVELONE_H
