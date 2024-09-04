#include "game/game.hpp"

GameScene::GameScene() {

}

void GameScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        engine->collision->clear();
        engine->camera->unfollow();
        engine->scene->unset();
        delete background;
        delete sound;
        delete fps_text;
        delete mouse_text;
        delete screen_text;
        delete game_time_text;
        delete game_score_text;
        delete mouse;
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
        engine->sound->pauseMusic();
        background = new Background();
        player = new Player();
        sound = new Sound();
        fps_text = new FPSText();
        mouse_text = new MouseText();
        screen_text = new ScreenText();
        bullet_manager = new BulletManager();
        enemy_manager = new EnemyManager();
        lives = new PlayerLives();
        game_time_text = new GameTimeText();
        game_score_text = new GameScoreText();
        mouse = new MouseImage();
        engine->scene->set([&]() {
            if (game_time_text->game_seconds > 5 * 60) {
                game->change_scene(game->winScene);
                return;
            }
            if (lives->count < 1) {
                game->change_scene(game->loseScene);
            }
        });
        
        engine->keyboard->add(SDL_SCANCODE_ESCAPE, [&]() {
            game->change_scene(game->menuScene);
        });
    }
}