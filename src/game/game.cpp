#include "game/game.hpp"

Game::Game() {
    menuScene = new MenuScene();
    gameScene = new GameScene();
    resultsScene = new ResultsScene();
    settingsScene = new SettingsScene();
    winScene = new WinScene();
    loseScene = new LoseScene();
    inputNameScene = new InputNameScene();

    // engine->keyboard->add(SDL_SCANCODE_C, [&]() {
    //     change_scene(loseScene);
    // });
    // engine->keyboard->add(SDL_SCANCODE_V, [&]() {
    //     change_scene(winScene);
    // });
}

void Game::start() {
    change_scene(menuScene);
    engine->start();
}

void Game::change_scene(SceneBase* scene) {
    if (current_scene != NULL) {
        current_scene->clear();
    }
    current_scene = scene;
    current_scene->start();
}
