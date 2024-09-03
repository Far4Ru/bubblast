#include "engine/manager/scene_manager.hpp"

SceneManager::SceneManager() {
    //
}

void SceneManager::process() {
    if (scene_switch_handler != NULL) {
        scene_switch_handler();
    }
}

void SceneManager::set(std::function<void()> func) {
    scene_switch_handler = func;
}

void SceneManager::unset() {
    scene_switch_handler = NULL;
}

