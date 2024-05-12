#include <iostream>
#include <SDL2/SDL.h>
#include "game/components/bullet.hpp"
#include <math.h>
// #include "game/components/utils/image_base.hpp"

Bullet::Bullet(Loader *loader) {
    this->image = loader->get("bullet");
}

void Bullet::create(SDL_Renderer *renderer) {
    int bW, bH;
    SDL_QueryTexture(this->image, NULL, NULL, &bW, &bH);
    this->applySurface(0, 0, this->image, renderer);
}

void Bullet::applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend, tex, NULL, &pos);
}

void Bullet::render(int x, int y, int bulletX, int bulletY, SDL_Renderer *renderer) {
    SDL_Rect player_RECT = { x + bulletX, y + bulletY, 100, 100 };
    SDL_RenderCopyEx(renderer, this->image, NULL, &player_RECT, 0, NULL, SDL_FLIP_NONE);
}