#include "game/game.hpp"

Game::Game() {
    Background* background = new Background();
    player = new Player();
    sound = new Sound();
    FPSText* fps_text = new FPSText();
    MouseText* mouse_text = new MouseText();
    bullet_manager = new BulletManager();
    enemy_manager = new EnemyManager();
    collision_manager = new CollisionManager();
    utils = new Utils();
}

void Game::start() {
    engine->start();
}
