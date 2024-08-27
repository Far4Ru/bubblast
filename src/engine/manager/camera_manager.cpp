#include "engine/manager/camera_manager.hpp"

CameraManager::CameraManager() {

}

void CameraManager::process() {
    // TODO: - add processing camera
    // x = follow_object.x - width / 2
    // y = follow_object.y - height / 2
    // width = width
    // height = height

    // other objects except the follow_object: x = ... + camera.x; y = ... + camera.y
}

void CameraManager::follow(RenderObject* object) {
    follow_object = object;
};
