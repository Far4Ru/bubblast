#include "game/game.hpp"

BulletManager::BulletManager() {
    timer.start();
    engine->keyboard->add(SDL_SCANCODE_SPACE, [&]() {
        if (timer.is_paused()) { return; }
        int ticks = timer.get_ticks();
        if (ticks > 10 * (1000 / 60)) {
            Bullet* bullet = new Bullet(game->gameScene->player->centerX(), game->gameScene->player->centerY());
            bullets.push_back(bullet);
            game->gameScene->sound->playFire();
            timer.start();
        }
    });
}

BulletManager::~BulletManager() {
    for (Bullet* bullet : bullets) {
        delete bullet;
    }
    std::vector<Bullet*>().swap(bullets);
    timer.stop();
    engine->keyboard->remove(SDL_SCANCODE_SPACE);
}
