#include <vector>
#include <iostream>
#include <algorithm>
#include "game/collision_object.hpp"

class CollisionManager {
    public:
        CollisionManager();
        void add(CollisionObject* object);
        void remove(CollisionObject* object);
    private:
        std::vector<CollisionObject*> collision_objects;
};
