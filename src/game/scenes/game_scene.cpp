#include "game/scenes/game_scene.hpp"

GameScene::GameScene() {

}

void GameScene::clear() {
    engine->renderer->clear();
    engine->collision->clear();
    engine->camera->unfollow();
    delete background;
    delete sound;
    delete fps_text;
    delete mouse_text;
    delete screen_text;
    delete bullet_manager;
    delete enemy_manager;
    player->destroy();
    // Error:
    // delete player;
}

void GameScene::start() {
    background = new Background();
    player = new Player();
    sound = new Sound();
    fps_text = new FPSText();
    mouse_text = new MouseText();
    screen_text = new ScreenText();
    bullet_manager = new BulletManager();
    enemy_manager = new EnemyManager();
}