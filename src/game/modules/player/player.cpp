#include "game/modules/player/player.hpp"

Player::Player() {
    player = engine->add->image("wizard");
    SDL_Rect crop = { 308, 199, 439, 629 };
    player->x = WIDTH / 2;
    player->y = HEIGHT / 2;
    player->scale = 0.25;
    engine->collision->add(this);
    player->crop = crop;
    player->width = crop.w;
    player->height = crop.h;
    engine->camera->follow(player);
    update();
    engine->keyboard->add(SDL_SCANCODE_UP, [&]() {
        move(MOVE_UP);
    });
    engine->keyboard->add(SDL_SCANCODE_W, [&]() {
        move(MOVE_UP);
    });
    engine->keyboard->add(SDL_SCANCODE_DOWN, [&]() {
        move(MOVE_DOWN);
    });
    engine->keyboard->add(SDL_SCANCODE_S, [&]() {
        move(MOVE_DOWN);
    });
    engine->keyboard->add(SDL_SCANCODE_LEFT, [&]() {
        move(MOVE_LEFT);
    });
    engine->keyboard->add(SDL_SCANCODE_A, [&]() {
        move(MOVE_LEFT);
    });
    engine->keyboard->add(SDL_SCANCODE_RIGHT, [&]() {
        move(MOVE_RIGHT);
    });
    engine->keyboard->add(SDL_SCANCODE_D, [&]() {
        move(MOVE_RIGHT);
    });
    type = PLAYER;
}

void Player::move(MoveType side) {
    switch (side) {
        case MOVE_UP:
            if (player->y < 150) { break; }
            player->y -= 10;
            break;
        case MOVE_LEFT:
            if (player->x < 150) { break; }
            player->x -= 10;
            player->turnLeft();
            break;
        case MOVE_RIGHT:
            if (player->x > WIDTH + 500) { break; }
            player->x += 10;
            player->turnRight();
            break;
        case MOVE_DOWN:
            if (player->y > HEIGHT + 150) { break; }
            player->y += 10;
            break;
    }
    update();
}


void Player::update() {
    player->setOffset(-engine->camera->x - (player->width / 2) * player->scale, -engine->camera->y - (player->height / 2) * player->scale);
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

int Player::centerX() {
    return x - (player->width / 2) * player->scale;
}

int Player::centerY() {
    return y - (player->height / 2) * player->scale;
}
