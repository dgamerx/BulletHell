#ifndef LEVEL_H
#define LEVEL_H


#include <Player.h>
#include <Bullet.h>
#include <Enemy.h>
#include <HealthBar.h>


class Level
{
    public:
        Level();
        virtual ~Level();

        virtual void update() = 0;

        virtual Player *getPlayer() = 0;
        virtual Enemy *getEnemy() = 0;
        virtual long long getFrameCounter();

        virtual void resetLevel() = 0;
        virtual void deleteLevelData() = 0;
        virtual void createLevelData() = 0;



    protected:
        long long frameCounter;
    private:


};


class levelOne : public Level {
    public:

        virtual ~levelOne();

        Player *getPlayer() override;
        Enemy *getEnemy() override;
        void resetLevel() override;


        void update() override;
        void deleteLevelData() override;
        void createLevelData() override;


        static levelOne *getInstance();
        static void createInstance();



    protected:
        jgl::Quad *q;
        jgl::Quad *eQ;
        jgl::Quad *enemyHealthBar;
        jgl::Quad *playerHealthBar;
    private:
        static levelOne *instance;
        levelOne();
        Player *p;
        Enemy *e;
        HealthBar *enemyHP;
        HealthBar *playerHP;


};

#endif // LEVEL_H
