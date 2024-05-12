#include <iostream>
#include <SDL2/SDL.h>
#include "game/components/player.hpp"
#include <math.h>
#include "game/loader.hpp"
// #include "game/components/utils/image_base.hpp"

Player::Player(Loader *loader) {
    this->image = loader->get("player");
}

void Player::create(SDL_Renderer *renderer) {
    int iW, iH;
    SDL_QueryTexture(this->image, NULL, NULL, &iW, &iH);
    int x = WIDTH / 2 - iW / 2;
    int y = HEIGHT / 2 - iH / 2;
    this->applySurface(x, y, this->image, renderer );
}

void Player::applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend, tex, NULL, &pos);
}

void Player::render(SDL_Renderer *renderer, int isRight) {
    SDL_Rect player_RECT = { 400, 300, 100, 100 };
    SDL_RenderCopyEx(renderer, this->image, NULL, &player_RECT, 0, NULL, isRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);
}