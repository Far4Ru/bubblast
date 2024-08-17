#include "game/game.hpp"

Game::Game() {
    Background* background = new Background();
    player = new Player();
    sound = new Sound();
    FPSText* fps_text = new FPSText();
    MouseText* mouse_text = new MouseText();
    bullet_manager = new BulletManager();
}

void Game::start() {
    engine->start();
}
