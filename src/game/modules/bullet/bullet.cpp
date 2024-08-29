#include "game/modules/bullet/bullet.hpp"
#include "game/game.hpp"

Bullet::Bullet(int x, int y) {
    bullet_image = engine->add->image("bullet_bubble");
    SDL_Rect crop = { 353, 292, 325, 361 };
    bullet_image->scale = 0.1;
    bullet_image->crop = crop;
    bullet_image->width = crop.w;
    bullet_image->height = crop.h;
    bullet_image->x = x;
    bullet_image->y = y;
    bullet_image->x -= (bullet_image->width / 2) * bullet_image->scale;
    bullet_image->y -= (bullet_image->height / 2) * bullet_image->scale;

    auto bullet_func = [&]() {
        // if (collision == ENEMY) {
        //     bullet_image->active = false;
        //     return;
        // }
        bullet_image->setOffset(-engine->camera->x , -engine->camera->y );
        if (life == MAX_BULLET_LIFE) {
            updateVelocity();
        }
        if (life > 0) {
            bullet_image->x += velocity.x * speed;
            bullet_image->y += velocity.y * speed;
            life--;
            updateSides();
        } else {
            bullet_image->active = false;
        }
    };
    bullet_image->setProcess(bullet_func);
    engine->collision->add(this);
    type = BULLET;
}

Bullet::~Bullet() {
    engine->collision->remove(this);
}

void Bullet::updateVelocity() {
    SDL_FPoint first;
    first.x = engine->mouse->x;
    first.y = engine->mouse->y;
    SDL_FPoint second;
    second.x = bullet_image->x + (bullet_image->height / 2 * bullet_image->scale);
    second.y = bullet_image->y + (bullet_image->width / 2 * bullet_image->scale);
    engine->axis_computing->computeVelocity(&first, &second, &velocity);
}

void Bullet::updateSides() {
    left = bullet_image->x;
    right = bullet_image->x + bullet_image->width * bullet_image->scale;
    top = bullet_image->y;
    bottom = bullet_image->y + bullet_image->height * bullet_image->scale;
}
