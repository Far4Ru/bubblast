#ifndef BULLET_H
#define BULLET_H

#include "engine/engine.hpp"

#define MAX_BULLET_LIFE 60

class Bullet {
    public:
        Bullet(int x, int y);
    private:
        void updateVelocity();
        int life = MAX_BULLET_LIFE;
        int speed = 10;
        ImageObject* bullet_image;
        SDL_FPoint velocity;
};

#endif
