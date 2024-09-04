#include "game/game.hpp"

WinScene::WinScene() {

}

void WinScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        delete background;
        delete title;
    }
}

void WinScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
        title = new WinTitle();
        // WinBackgroundImage
        // WinResultText
        // BackMenuButton
        restart = new RestartButton();
        back_to_menu = new BackMenuButton();
        engine->sound->playMusic("win_sound", false);
        engine->scene->set([&]() {
            if (restart->pressed) {
                game->change_scene(game->gameScene);
            } else if (back_to_menu->pressed) {
                game->change_scene(game->menuScene);
            }
        });
    }
}