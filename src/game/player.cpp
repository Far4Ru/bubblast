#include "game/player.hpp"

Player::Player() {
    player = engine->add->image("wizard");
    player->x = 50;
    player->scale = 0.25;
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
}

void Player::update() {
    x = player->x + (player->width / 2) * player->scale;
    y = player->y + (player->height / 2) * player->scale;
}

void Player::updateVelocity() {
    
}
