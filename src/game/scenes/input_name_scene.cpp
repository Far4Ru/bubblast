#include "game/game.hpp"

InputNameScene::InputNameScene() {

}

void InputNameScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        engine->scene->unset();
        delete background;
        delete title;
        delete inputNameField;
        delete start_button;
        delete back_to_menu;
    }
}

void InputNameScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
        title = new InputNameTitle();
        inputNameField = new InputNameField();
        inputNameField->setName(game->player_name);
        start_button = new StartButton();
        back_to_menu = new BackMenuButton();
        engine->scene->set([&]() {
            game->player_name = inputNameField->getName();
            start_button->setActive(game->player_name.size() != 0);
            if (start_button->pressed) {
                game->change_scene(game->gameScene);
            } else if (back_to_menu->pressed) {
                game->change_scene(game->menuScene);
            }
        });
    }
}