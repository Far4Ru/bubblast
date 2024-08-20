#include "engine/collision/collision_manager.hpp"

CollisionManager::CollisionManager() {

}

void CollisionManager::add(CollisionObject* object) {
    collision_objects.push_back(object);
}

void CollisionManager::remove(CollisionObject* object) {
    collision_objects.erase(std::remove(collision_objects.begin(), collision_objects.end(), object), collision_objects.end());
}

void CollisionManager::check() {
    
}
