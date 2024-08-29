#include "engine/manager/camera_manager.hpp"

CameraManager::CameraManager() {
    width = WIDTH;
    height = HEIGHT;
}

void CameraManager::process() {
    if (follow_object) {
        x = follow_object->x - width / 2;
        y = follow_object->y - height / 2;
    }

    // other objects except the follow_object: x = ... + camera.x; y = ... + camera.y
}

void CameraManager::follow(ImageObject* object) {
    follow_object = object;
};
