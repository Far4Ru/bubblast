#include "game/bullet_manager.hpp"

BulletManager::BulletManager() {
    timer.start();
    engine->keyboard->add(SDL_SCANCODE_SPACE, [&]() {
        int ticks = timer.get_ticks();
        if (ticks > 10 * (1000 / 60)) {
            Bullet* bullet = new Bullet();
            timer.start();
        }
    });
}
