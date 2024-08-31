#include "game/scenes/menu_scene.hpp"

MenuScene::MenuScene() {

}

void MenuScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        delete background;
    }
}

void MenuScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
    }
}