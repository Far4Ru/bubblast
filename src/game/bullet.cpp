#include "game/bullet.hpp"

Bullet::Bullet() {
    ImageObject* bullet = engine->add->image("bullet_bubble");
    bullet->scale = 0.1;
    bullet->y -= (bullet->height / 2 * bullet->scale);
    bullet->x -= (bullet->width / 2) * bullet->scale;

    auto mouse_text_func = [&, bullet]() {
        int speed = 10;
        SDL_FPoint first;
        first.x = engine->mouse->x;
        first.y = engine->mouse->y;
        SDL_FPoint second;
        second.x = bullet->x + (bullet->height / 2 * bullet->scale);
        second.y = bullet->y + (bullet->width / 2 * bullet->scale);
        SDL_FPoint velocity;
        calc(&first, &second, &velocity);
        bullet->x += velocity.x * speed;
        bullet->y += velocity.y * speed;
    };
    bullet->setProcess(mouse_text_func);
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
