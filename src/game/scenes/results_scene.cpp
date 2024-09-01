#include "game/game.hpp"

ResultsScene::ResultsScene() {

}

void ResultsScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        delete background;
        engine->keyboard->remove(SDL_SCANCODE_ESCAPE);
    }
}

void ResultsScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
        
        engine->keyboard->add(SDL_SCANCODE_ESCAPE, [&]() {
            game->resultsScene->clear();
            game->menuScene->start();
        });
    }
}