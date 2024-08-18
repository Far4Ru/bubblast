#include "game/game.hpp"

Enemy::Enemy(int x, int y) {
    enemy_image = engine->add->image("candy_1");
    enemy_image->scale = 0.5;
    enemy_image->x = x;
    enemy_image->y = y;
    enemy_image->y -= (enemy_image->width / 2 * enemy_image->scale);
    enemy_image->x -= (enemy_image->height / 2) * enemy_image->scale;
    auto bullet_func = [&]() {
        updateVelocity();
    };
    enemy_image->setProcess(bullet_func);
}

void Enemy::updateVelocity() {
    SDL_FPoint first;
    first.x = game->player->x;
    first.y = game->player->y;
    SDL_FPoint second;
    second.x = enemy_image->x + (enemy_image->width / 2 * enemy_image->scale);
    second.y = enemy_image->y + (enemy_image->height / 2 * enemy_image->scale);
    game->utils->calc(&first, &second, &velocity);

    enemy_image->x += velocity.x * 3;
    enemy_image->y += velocity.y * 3;
}
