#include "game/game.hpp"

Game::Game() {
    gameScene = new GameScene();
    engine->keyboard->add(SDL_SCANCODE_C, [&]() {
        gameScene->clear();
    });
    engine->keyboard->add(SDL_SCANCODE_V, [&]() {
        gameScene->start();
    });
}

void Game::start() {
    gameScene->start();
    engine->start();
}
