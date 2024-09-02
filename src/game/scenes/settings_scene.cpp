#include "game/game.hpp"

SettingsScene::SettingsScene() {

}

void SettingsScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        delete background;
        engine->keyboard->remove(SDL_SCANCODE_ESCAPE);
    }
}

void SettingsScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
        
        engine->keyboard->add(SDL_SCANCODE_ESCAPE, [&]() {
            game->change_scene(game->menuScene);
        });
    }
}