#include "engine/engine.hpp"
#include "game/collision_object.hpp"
 
class Player : public CollisionObject {
    public:
        Player();
        int x = 0, y = 0;
        void updateVelocity();
    private:
        ImageObject* player;
        void update();
};
