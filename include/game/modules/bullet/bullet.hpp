#ifndef BULLET_H
#define BULLET_H

#include "engine/engine.hpp"
#include "engine/entity/collision_object.hpp"

#define MAX_BULLET_LIFE 600

class Bullet : public CollisionObject {
    public:
        Bullet(int x, int y);
        ~Bullet();

        void updateVelocity();
        void updateSides();
    private:
        bool active = true;
        bool to_destroy = false;
        int life = MAX_BULLET_LIFE;
        int speed = 10;
        ImageObject* bullet_image;
};

#endif
