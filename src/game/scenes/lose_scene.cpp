#include "game/game.hpp"

LoseScene::LoseScene() {

}

void LoseScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        delete background;
    }
}

void LoseScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
    }
}