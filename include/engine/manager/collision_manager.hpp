#include <vector>
#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include "engine/entity/collision_object.hpp"

class CollisionManager {
    public:
        CollisionManager();
        void add(CollisionObject* object);
        void remove(CollisionObject* object);
        void process();
        bool check(CollisionObject* first, CollisionObject* second);
    private:
        std::vector<CollisionObject*> collision_objects;
};
