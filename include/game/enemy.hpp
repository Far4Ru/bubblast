#include "engine/engine.hpp"

class Enemy : public CollisionObject  {
    public:
        Enemy(int x, int y, std::string name);
        void updateVelocity();
    private:
        ImageObject* enemy_image;
        SDL_FPoint velocity;
};
