#include "engine/manager/camera_manager.hpp"

CameraManager::CameraManager() {
    width = WIDTH;
    height = HEIGHT;
}

void CameraManager::process() {
    if (follow_object != nullptr) {
        x = follow_object->x - width / 2;
        y = follow_object->y - height / 2;
    }
}

void CameraManager::follow(ImageObject* object) {
    follow_object = object;
};

void CameraManager::unfollow() {
    follow_object = nullptr;
};
