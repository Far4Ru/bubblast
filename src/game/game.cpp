#include "game/game.hpp"

Game::Game() {
    menuScene = new MenuScene();
    gameScene = new GameScene();
    resultsScene = new ResultsScene();
    settingsScene = new SettingsScene();
    winScene = new WinScene();
    loseScene = new LoseScene();

    engine->keyboard->add(SDL_SCANCODE_C, [&]() {
        gameScene->clear();
        menuScene->start();
    });
    engine->keyboard->add(SDL_SCANCODE_V, [&]() {
        menuScene->clear();
        gameScene->start();
    });
}

void Game::start() {
    menuScene->start();
    engine->start();
}
