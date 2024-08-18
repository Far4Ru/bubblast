#include "engine/engine.hpp"

class Enemy {
    public:
        Enemy(int x, int y);
        void updateVelocity();
    private:
        ImageObject* enemy_image;
        SDL_FPoint velocity;
};
