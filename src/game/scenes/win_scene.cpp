#include "game/game.hpp"
#include "engine/utils/file.hpp"

WinScene::WinScene() {

}

void WinScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        engine->scene->unset();
        delete background;
        delete title;
        delete score;
    }
}

void WinScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
        title = new WinTitle();
        // WinBackgroundImage
        score = new ScoreText();
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
