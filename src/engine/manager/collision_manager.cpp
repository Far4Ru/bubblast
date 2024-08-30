#include "engine/manager/collision_manager.hpp"

CollisionManager::CollisionManager() {

}

void CollisionManager::add(CollisionObject* object) {
    collision_objects.push_back(object);
}

void CollisionManager::remove(CollisionObject* object) {
    collision_objects.erase(std::remove(collision_objects.begin(), collision_objects.end(), object), collision_objects.end());
}

void CollisionManager::clear() {
    for (CollisionObject* object : collision_objects) {
        remove(object);
    }
}

void CollisionManager::process() {
    if (collision_objects.size() > 0) {
        for (std::vector<CollisionObject*>::size_type i = 0; i != collision_objects.size() - 1; i++) {
            for (std::vector<CollisionObject*>::size_type j = i + 1; j != collision_objects.size(); j++) {
                bool isCollide = check(collision_objects[i], collision_objects[j]);
                if (isCollide) {
                    collision_objects[i]->collision = collision_objects[j]->type;
                    collision_objects[j]->collision = collision_objects[i]->type;
                }
            }
        }
    }
}

bool CollisionManager::check(CollisionObject* first, CollisionObject* second) {
    return (first->bottom > second->top) &
            (first->top < second->bottom) &
            (first->right > second->left) &
            (first->left < second->right);
}
