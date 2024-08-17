#include "game/bullet_manager.hpp"

BulletManager::BulletManager() {
    engine->keyboard->add(SDL_SCANCODE_SPACE, [&]() {
        Bullet* bullet = new Bullet();
    });
}
