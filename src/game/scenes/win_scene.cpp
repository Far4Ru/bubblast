#include "game/game.hpp"
#include "engine/utils/file.hpp"

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
        save_result();
    }
}

void WinScene::save_result() {
    File::init_file("results.data");
    std::ofstream data_file;
    data_file.open("results.data", std::ios_base::app);
    data_file << "\nPlayer - 0";
}
