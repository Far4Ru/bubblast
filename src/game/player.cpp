#include "game/player.hpp"

Player::Player() {
    ImageObject* player = engine->add->image("wizard");
    player->x = 50;
    player->scale = 0.25;
    engine->keyboard->add(SDL_SCANCODE_UP, [&, player]() {
        if (player->y > 0) {
            player->y -= 10;
        }
    });
    engine->keyboard->add(SDL_SCANCODE_W, [&, player]() {
        if (player->y > 0) {
            player->y -= 10;
        }
    });
    engine->keyboard->add(SDL_SCANCODE_DOWN, [&, player]() {
        if (player->y < HEIGHT) {
            player->y += 10;
        }
    });
    engine->keyboard->add(SDL_SCANCODE_S, [&, player]() {
        if (player->y < HEIGHT) {
            player->y += 10;
        }
    });
    engine->keyboard->add(SDL_SCANCODE_LEFT, [&, player]() {
        if (player->x > 0) {
            player->x -= 10;
            player->turnLeft();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_A, [&, player]() {
        if (player->x > 0) {
            player->x -= 10;
            player->turnLeft();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_RIGHT, [&, player]() {
        if (player->x < WIDTH) {
            player->x += 10;
            player->turnRight();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_D, [&, player]() {
        if (player->x < WIDTH) {
            player->x += 10;
            player->turnRight();
        }
    });
}
