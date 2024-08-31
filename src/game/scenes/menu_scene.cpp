#include "game/scenes/menu_scene.hpp"

MenuScene::MenuScene() {

}

void MenuScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        delete background;
        delete logo;
        delete play;
    }
}

void MenuScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
        logo = new Logo();
        play = new PlayButton();
    }
}