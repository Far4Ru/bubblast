#include "game/game.hpp"

LoseScene::LoseScene() {

}

void LoseScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        delete background;
        delete title;
        delete restart;
        delete back_to_menu;
    }
}

void LoseScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
        title = new LoseTitle();
        restart = new RestartButton();
        back_to_menu = new BackMenuButton();
        engine->sound->playMusic("lose_sound", false);
        engine->scene->set([&]() {
            if (restart->pressed) {
                game->change_scene(game->gameScene);
            } else if (back_to_menu->pressed) {
                game->change_scene(game->menuScene);
            }
        });
    }
}