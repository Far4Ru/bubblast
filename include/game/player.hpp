#include "engine/engine.hpp"
#include "engine/collision/collision_object.hpp"
 
class Player : public CollisionObject {
    public:
        Player();
        int x = 0, y = 0;
        void updateVelocity();
        void updateSides();
    private:
        ImageObject* player;
        void update();
};
