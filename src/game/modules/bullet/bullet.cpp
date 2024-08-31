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
        if (!active) { return; }
        if (collision == ENEMY) {
            active = false;
            bullet_image->active = false;
            to_destroy = true;
            engine->collision->remove(this);
            return;
        }
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
            to_destroy = true;
        }
    };
    bullet_image->setProcess(bullet_func);
    engine->collision->add(this);
    type = BULLET;
}

Bullet::~Bullet() {
    engine->collision->remove(this);
    bullet_image->destroy();
}

void Bullet::updateVelocity() {
    SDL_FPoint bullet_position;
    bullet_position.x = bullet_image->x + (bullet_image->height / 2 * bullet_image->scale);
    bullet_position.y = bullet_image->y + (bullet_image->width / 2 * bullet_image->scale);
    SDL_FPoint mouse_position;
    mouse_position.x = bullet_position.x - (WIDTH / 2) * engine->game_area->scale + engine->mouse->x;
    mouse_position.y = bullet_position.y - (HEIGHT / 2) * engine->game_area->scale + engine->mouse->y;
    engine->axis_computing->computeVelocity(&mouse_position, &bullet_position, &velocity);
}

void Bullet::updateSides() {
    left = bullet_image->x;
    right = bullet_image->x + bullet_image->width * bullet_image->scale;
    top = bullet_image->y;
    bottom = bullet_image->y + bullet_image->height * bullet_image->scale;
}
