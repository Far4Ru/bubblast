#include "game/player.hpp"

Player::Player() {
    player = engine->add->image("wizard");
    SDL_Rect crop = { 308, 199, 439, 629 };
    player->x = 50;
    player->scale = 0.25;
    engine->collision->add(this);
    player->crop = crop;
    player->width = crop.w;
    player->height = crop.h;
    update();
    engine->keyboard->add(SDL_SCANCODE_UP, [&]() {
        if (player->y > 0) {
            player->y -= 10;
            update();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_W, [&]() {
        if (player->y > 0) {
            player->y -= 10;
            update();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_DOWN, [&]() {
        if (player->y < HEIGHT) {
            player->y += 10;
            update();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_S, [&]() {
        if (player->y < HEIGHT) {
            player->y += 10;
            update();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_LEFT, [&]() {
        if (player->x > 0) {
            player->x -= 10;
            player->turnLeft();
            update();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_A, [&]() {
        if (player->x > 0) {
            player->x -= 10;
            player->turnLeft();
            update();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_RIGHT, [&]() {
        if (player->x < WIDTH) {
            player->x += 10;
            player->turnRight();
            update();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_D, [&]() {
        if (player->x < WIDTH) {
            player->x += 10;
            player->turnRight();
            update();
        }
    });
    type = PLAYER;
}

void Player::update() {
    x = player->x + (player->width / 2) * player->scale;
    y = player->y + (player->height / 2) * player->scale;
}

void Player::updateVelocity() {
    updateSides();
}

void Player::updateSides() {
    left = player->x;
    right = player->x + player->width * player->scale;
    top = player->y;
    bottom = player->y + player->height * player->scale;
}
