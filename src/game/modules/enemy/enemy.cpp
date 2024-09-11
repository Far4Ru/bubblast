#include "game/game.hpp"

Enemy::Enemy(int x, int y, std::string name) {
    enemy_image = engine->add->image(name);
    SDL_Rect crop = {0, 0, enemy_image->width, enemy_image->height };
    if (name == "candy_1") {
        crop = { 290, 395, 370, 187 };
        hits = 1;
        points = 1;
    } else if (name == "candy_2") {
        crop = { 345, 402, 251, 197 };
        hits = 2;
        points = 2;
    } else if (name == "candy_3") {
        crop = { 383, 348, 154, 247 };
        hits = 3;
        points = 3;
    } else if (name == "candy_4") {
        crop = { 361, 384, 213, 207 };
        hits = 4;
        points = 4;
    } else if (name == "candy_5") {
        crop = { 374, 337, 131, 275 };
        hits = 5;
        points = 5;
    }
    enemy_image->scale = 0.2;
    enemy_image->crop = crop;
    enemy_image->width = crop.w;
    enemy_image->height = crop.h;
    enemy_image->x = x - (enemy_image->width / 2);
    enemy_image->y = y - (enemy_image->height / 2);
    auto bullet_func = [&]() {
        if (!active) { return; }
        enemy_image->setOffset(-engine->camera->x , -engine->camera->y );
        updateSides();
        if (collision != NULL) {
            if (collision->type == BULLET) {
                if (hits > 1) {
                    enemy_image->x += collision->velocity.x * 100;
                    enemy_image->y += collision->velocity.y * 100;
                }
                collision = NULL;
                hits--;
                if (hits < 1) {
                    game->gameScene->game_score_text->game_score += points;
                    game->gameScene->enemy_manager->kill(this);
                    active = false;
                    to_destroy = true;
                    left = 0;
                    right = 0;
                    top = 0;
                    bottom = 0;
                    return;
                }
            } else if (collision->type == ENEMY && !collision->proccessed) {
                enemy_image->x -= velocity.x * 6;
                enemy_image->y -= velocity.y * 6;
                proccessed = true;
                collision = NULL;
                engine->collision->remove(this);
                engine->collision->add(this);
            }
        }
        updateVelocity();
    };
    enemy_image->setProcess(bullet_func);
    engine->collision->add(this);
    type = ENEMY;
}

Enemy::~Enemy() {
    engine->collision->remove(this);
}

void Enemy::updateVelocity() {
    SDL_FPoint player_position;
    player_position.x = game->gameScene->player->centerX();
    player_position.y = game->gameScene->player->centerY();
    SDL_FPoint enemy_position;
    enemy_position.x = enemy_image->x + (enemy_image->width / 2 * enemy_image->scale);
    enemy_position.y = enemy_image->y + (enemy_image->height / 2 * enemy_image->scale);
    engine->axis_computing->computeVelocity(&player_position, &enemy_position, &velocity);

    enemy_image->x += velocity.x * 2;
    enemy_image->y += velocity.y * 2;
}

void Enemy::updateSides() {
    left = enemy_image->x;
    right = enemy_image->x + enemy_image->width * enemy_image->scale;
    top = enemy_image->y;
    bottom = enemy_image->y + enemy_image->height * enemy_image->scale;
}

void Enemy::destroy() {
    enemy_image->active = false;
    enemy_image->to_destroy = true;
    this->~Enemy();
}
