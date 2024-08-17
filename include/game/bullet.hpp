#include "engine/engine.hpp"
#include <iostream>

#define MAX_BULLET_LIFE 60

class Bullet {
    public:
        Bullet(int x, int y);
    private:
        void calc(SDL_FPoint* first, SDL_FPoint* second, SDL_FPoint* velocity);
        void updateVelocity();
        int life = MAX_BULLET_LIFE;
        int speed = 10;
        ImageObject* bullet_image;
        SDL_FPoint velocity;
};
