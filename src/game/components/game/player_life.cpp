#include "game/components/game/player_life.hpp"

PlayerLife::PlayerLife(int number) {
    image = engine->add->image("heart");
    image->scale = 0.25;
    image->x = number * 70 - 40;
    image->y = -70;
    image->active = true;
    image_inactive = engine->add->image("heart_empty");
    image_inactive->scale = 0.25;
    image_inactive->x = number * 70 - 40;
    image_inactive->y = -70;
    image_inactive->active = false;
}

PlayerLife::~PlayerLife() {
    image->destroy();
    image_inactive->destroy();
}

void PlayerLife::inactive() {
    image->active = false;
    image_inactive->active = true;
}

void PlayerLife::destroy() {
    image->active = false;
    image->to_destroy = true;
    image_inactive->active = false;
    image_inactive->to_destroy = true;
    this->~PlayerLife();
}
