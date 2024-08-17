#include "game/bullet.hpp"

Bullet::Bullet(int x, int y) {
    bullet_image = engine->add->image("bullet_bubble");
    bullet_image->scale = 0.1;
    bullet_image->x = x;
    bullet_image->y = y;
    bullet_image->y -= (bullet_image->height / 2 * bullet_image->scale);
    bullet_image->x -= (bullet_image->width / 2) * bullet_image->scale;

    auto bullet_func = [&]() {
        if (life == MAX_BULLET_LIFE) {
            updateVelocity();
        }
        if (life > 0) {
            bullet_image->x += velocity.x * speed;
            bullet_image->y += velocity.y * speed;
            life--;
        } else {
            bullet_image->active = false;
        }
    };
    bullet_image->setProcess(bullet_func);
}

void Bullet::updateVelocity() {
    SDL_FPoint first;
    first.x = engine->mouse->x;
    first.y = engine->mouse->y;
    SDL_FPoint second;
    second.x = bullet_image->x + (bullet_image->height / 2 * bullet_image->scale);
    second.y = bullet_image->y + (bullet_image->width / 2 * bullet_image->scale);
    calc(&first, &second, &velocity);
}

void Bullet::calc(SDL_FPoint* first, SDL_FPoint* second, SDL_FPoint* velocity) {
    int steps = std::max(abs(first->x - second->x), abs(first->y - second->y));

    if (steps == 0) {
        velocity->x = velocity->y = 0;
        return;
    }

    velocity->x = (first->x - second->x) / steps;
    velocity->y = (first->y - second->y) / steps;
}
