#include <vector>
#include <iostream>
#include "game/collision_object.hpp"

class CollisionManager {
    public:
        CollisionManager();
        void add();
    private:
        std::vector<CollisionObject*> collision_objects;
};
