#ifndef BULLET_H
#define BULLET_H

#include "Sprite.h"

#define PLAYER_BULLET_VELOCITY 10
#define ENEMY_BULLET_VELOCITY 17

class Bullet: public Sprite
{
    public:

    virtual ~Bullet();
    static void shoot();
    static void enemyShoot(jml::Vector2ld, long double = 17);
    static void moveBullet();
    static void targetFire(long double, long double);
    static void enemyLineFire();
    static jutil::Queue<Bullet> bullets;
    static jutil::Queue<Bullet> enemyBullets;

    static bool collision(Bullet*);
    static bool playerCollision(Bullet*);

    bool operator==(Bullet);
    static bool collide(Bullet*);

    //void setAngle(jml::Angle);
    jml::Angle getAngle();

    protected:

    private:
        Bullet(pVar p, dVar d, jgl::Color c, jutil::String str);
        jml::Angle angle;
        long double pAngle;
        int dmg;
        long double velocity;
        jgl::Triangle bQ;



};

#endif // BULLET_H
