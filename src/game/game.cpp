#include "game/game.hpp"

Game::Game() {
    Background* background = new Background();
    Player* player = new Player();
    Sound* sound = new Sound();
    FPSText* fps_text = new FPSText();
    MouseText* mouse_text = new MouseText();
    BulletManager* bullet_manager = new BulletManager();
    engine->start();
}