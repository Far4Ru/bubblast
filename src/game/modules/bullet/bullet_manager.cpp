#include "game/game.hpp"

BulletManager::BulletManager() {
    timer.start();
    engine->keyboard->add(SDL_SCANCODE_SPACE, [&]() {
        if (timer.is_paused()) { return; }
        int ticks = timer.get_ticks();
        if (ticks > 10 * (1000 / 60)) {
            Bullet* bullet = new Bullet(game->gameScene->player->centerX(), game->gameScene->player->centerY());
            game->gameScene->sound->playFire();
            timer.start();
        }
    });
}

BulletManager::~BulletManager() {
    timer.stop();
    engine->keyboard->remove(SDL_SCANCODE_SPACE);
}
