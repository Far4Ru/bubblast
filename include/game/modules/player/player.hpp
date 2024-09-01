#include "engine/engine.hpp"
#include "engine/entity/collision_object.hpp"


enum MoveType {
  MOVE_NONE,
  MOVE_UP,
  MOVE_LEFT,
  MOVE_RIGHT,
  MOVE_DOWN,
};

class Player : public CollisionObject {
    public:
        Player();
        ~Player();
        void destroy();

        int x = 0, y = 0;
        void updateVelocity();
        void updateSides();
        int centerX();
        int centerY();
    private:
        int last_hit_seconds = 0;
        ImageObject* player;
        void update();
        void move(MoveType side);
};
