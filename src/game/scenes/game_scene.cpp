#include "game/game.hpp"

GameScene::GameScene() {

}

void GameScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        engine->collision->clear();
        engine->camera->unfollow();
        delete background;
        delete sound;
        delete fps_text;
        delete mouse_text;
        delete screen_text;
        delete lives;
        delete bullet_manager;
        delete enemy_manager;
        delete player;
        engine->keyboard->remove(SDL_SCANCODE_ESCAPE);
    }
}

void GameScene::start() {
    if (!this->active) {
        this->active = true;
        background = new Background();
        player = new Player();
        sound = new Sound();
        fps_text = new FPSText();
        mouse_text = new MouseText();
        screen_text = new ScreenText();
        bullet_manager = new BulletManager();
        enemy_manager = new EnemyManager();
        lives = new PlayerLives();
        
        engine->keyboard->add(SDL_SCANCODE_ESCAPE, [&]() {
            game->gameScene->clear();
            game->menuScene->start();
        });
    }
}