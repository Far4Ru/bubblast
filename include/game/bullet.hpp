#ifndef BULLET_H
#define BULLET_H

#include "engine/engine.hpp"
#include "engine/collision/collision_object.hpp"

#define MAX_BULLET_LIFE 60

class Bullet : public CollisionObject {
    public:
        Bullet(int x, int y);
        ~Bullet();

        void updateVelocity();
        void updateSides();
    private:
        int life = MAX_BULLET_LIFE;
        int speed = 10;
        ImageObject* bullet_image;
        SDL_FPoint velocity;
};

#endif
