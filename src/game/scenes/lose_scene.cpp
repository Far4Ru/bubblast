#include "game/scenes/lose_scene.hpp"

LoseScene::LoseScene() {

}

void LoseScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
    }
}

void LoseScene::start() {
    if (!this->active) {
        this->active = true;
    }
}