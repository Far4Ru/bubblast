#include "game/game.hpp"

ResultsScene::ResultsScene() {

}

void ResultsScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        delete background;
        delete title;
        delete table;
        delete back_to_menu;
        engine->keyboard->remove(SDL_SCANCODE_ESCAPE);
    }
}

void ResultsScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
        title = new ResultsTitleText();
        table = new ResultsTable();
        back_to_menu = new BackMenuButton();

        engine->scene->set([&]() {
            if (back_to_menu->pressed) {
                game->change_scene(game->menuScene);
            }
        });
        
        engine->keyboard->add(SDL_SCANCODE_ESCAPE, [&]() {
            game->change_scene(game->menuScene);
        });
    }
}