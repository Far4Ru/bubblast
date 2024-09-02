#include "game/game.hpp"

WinScene::WinScene() {

}

void WinScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        delete background;
    }
}

void WinScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
    }
}