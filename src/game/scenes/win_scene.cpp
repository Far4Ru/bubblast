#include "game/scenes/win_scene.hpp"

WinScene::WinScene() {

}

void WinScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
    }
}

void WinScene::start() {
    if (!this->active) {
        this->active = true;
    }
}