#include "game/game.hpp"

Player::Player() {
    player = engine->add->image("wizard");
    SDL_Rect crop = { 308, 199, 439, 629 };
    player->x = WIDTH / 2;
    player->y = HEIGHT / 2;
    player->scale = 0.1;
    engine->collision->add(this);
    player->crop = crop;
    player->width = crop.w;
    player->height = crop.h;
    timer.start();
    auto player_func = [&]() {
        player->x += moveX;
        player->y += moveY;
        moveX = 0;
        moveY = 0;
        update();
        updateSides();
        int ticks = timer.get_ticks();
        if (ticks > 1000) {
            if (collision != NULL && collision->type == ENEMY) {
                timer.start();
                game->gameScene->lives->reduce();
            }
        } else {
            collision = NULL;
        }
    };
    player->setProcess(player_func);
    engine->camera->follow(player);
    engine->camera->process();
    update();
    player_func();
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

Player::~Player() {
    destroy();
}

void Player::destroy() {
    timer.stop();
    engine->collision->remove(this);
    player->destroy();
    engine->keyboard->remove(SDL_SCANCODE_UP);
    engine->keyboard->remove(SDL_SCANCODE_W);
    engine->keyboard->remove(SDL_SCANCODE_DOWN);
    engine->keyboard->remove(SDL_SCANCODE_S);
    engine->keyboard->remove(SDL_SCANCODE_LEFT);
    engine->keyboard->remove(SDL_SCANCODE_A);
    engine->keyboard->remove(SDL_SCANCODE_RIGHT);
    engine->keyboard->remove(SDL_SCANCODE_D);
}

void Player::move(MoveType side) {
    switch (side) {
        case MOVE_UP:
            if (player->y < 115) { break; }
            moveY = -10;
            break;
        case MOVE_LEFT:
            if (player->x < 115) { break; }
            moveX = -10;
            player->turnLeft();
            break;
        case MOVE_RIGHT:
            if (player->x > WIDTH + 500) { break; }
            moveX = 10;
            player->turnRight();
            break;
        case MOVE_DOWN:
            if (player->y > HEIGHT + 190) { break; }
            moveY = 10;
            break;
    }
}


void Player::update() {
    player->setOffset(-engine->camera->x - (player->width / 2) * player->scale, -engine->camera->y - (player->height / 2) * player->scale);
    x = player->x + (player->width / 2) * player->scale;
    y = player->y + (player->height / 2) * player->scale;
}

void Player::updateVelocity() {
    // updateSides();
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
