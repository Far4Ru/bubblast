#include "game/game.hpp"

MenuScene::MenuScene() {

}

void MenuScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        engine->scene->unset();
        delete background;
        delete logo;
        delete play;
        delete settings;
        delete results;
        delete exit;
    }
}

void MenuScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
        logo = new Logo();
        play = new PlayButton();
        settings = new SettingsButton();
        results = new ResultsButton();
        exit = new ExitButton();
        engine->scene->set([&]() {
            if (play->pressed) {
                game->change_scene(game->gameScene);
            } else if (results->pressed) {
                game->change_scene(game->resultsScene);
            } else if (settings->pressed) {
                game->change_scene(game->settingsScene);
            }
        });
    }
}