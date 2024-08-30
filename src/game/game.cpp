#include "game/game.hpp"

Game::Game() {
    // Scene1
    // Button play_button = new PlayButton();
    // Scene2
    Background* background = new Background();
    player = new Player();
    sound = new Sound();
    FPSText* fps_text = new FPSText();
    MouseText* mouse_text = new MouseText();
    ScreenText* screen_text = new ScreenText();
    bullet_manager = new BulletManager();
    enemy_manager = new EnemyManager();
    // engine->add->scene(Scene1);
    // engine->add->scene(Scene2);
}

void Game::start() {
    engine->start();
    // engine->start->scene(Scene2);
}
