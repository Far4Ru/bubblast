#include <vector>
#include <iostream>
#include <algorithm>
#include "engine/collision/collision_object.hpp"

class CollisionManager {
    public:
        CollisionManager();
        void add(CollisionObject* object);
        void remove(CollisionObject* object);
        void check();
    private:
        std::vector<CollisionObject*> collision_objects;
};
