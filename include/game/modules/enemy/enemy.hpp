#include "engine/engine.hpp"
#include "engine/entity/collision_object.hpp"

class Enemy : public CollisionObject  {
    public:
        Enemy(int x, int y, std::string name);
        ~Enemy();

        void updateVelocity();
        void updateSides();
        void destroy();
    private:
        ImageObject* enemy_image;
        SDL_FPoint velocity;
        bool active = true;
};
