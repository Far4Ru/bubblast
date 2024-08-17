#include "game/game.hpp"

BulletManager::BulletManager() {
    timer.start();
    engine->keyboard->add(SDL_SCANCODE_SPACE, [&]() {
        int ticks = timer.get_ticks();
        if (ticks > 10 * (1000 / 60)) {
            Bullet* bullet = new Bullet(game->player->x, game->player->y);
            timer.start();
        }
    });
}
