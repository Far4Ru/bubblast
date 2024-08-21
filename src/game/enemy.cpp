#include "game/game.hpp"

Enemy::Enemy(int x, int y, std::string name) {
    enemy_image = engine->add->image(name);
    SDL_Rect crop = {0, 0, enemy_image->width, enemy_image->height };
    if (name == "candy_1") {
        crop = { 290, 395, 370, 187 };
    } else if (name == "candy_2") {
        crop = { 345, 402, 251, 197 };
    }
    enemy_image->scale = 0.5;
    enemy_image->crop = crop;
    enemy_image->width = crop.w;
    enemy_image->height = crop.h;
    enemy_image->x = x;
    enemy_image->y = y;
    enemy_image->x -= (enemy_image->width / 2) * enemy_image->scale;
    enemy_image->y -= (enemy_image->height / 2) * enemy_image->scale;
    auto bullet_func = [&]() {
        if (collision == BULLET) {
            game->enemy_manager->kill(this);
            return;
        }
        updateVelocity();
    };
    enemy_image->setProcess(bullet_func);
    engine->collision->add(this);
    type = ENEMY;
}

Enemy::~Enemy() {

}

void Enemy::updateVelocity() {
    SDL_FPoint first;
    first.x = game->player->x;
    first.y = game->player->y;
    SDL_FPoint second;
    second.x = enemy_image->x + (enemy_image->width / 2 * enemy_image->scale);
    second.y = enemy_image->y + (enemy_image->height / 2 * enemy_image->scale);
    engine->axis_computing->computeVelocity(&first, &second, &velocity);

    enemy_image->x += velocity.x * 3;
    enemy_image->y += velocity.y * 3;
    updateSides();
}

void Enemy::updateSides() {
    left = enemy_image->x - (enemy_image->width / 2) * enemy_image->scale;
    right = enemy_image->x + (enemy_image->width / 2) * enemy_image->scale;
    top = enemy_image->y - (enemy_image->height / 2) * enemy_image->scale;
    bottom = enemy_image->y + (enemy_image->height / 2) * enemy_image->scale;
}

void Enemy::destroy() {
    enemy_image->active = false;
    this->~Enemy();
}
