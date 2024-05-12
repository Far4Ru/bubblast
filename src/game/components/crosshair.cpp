#include <iostream>
#include <SDL2/SDL.h>
#include "game/components/crosshair.hpp"
#include <math.h>
#include <game/loader.hpp>
// #include "game/components/utils/image_base.hpp"

Crosshair::Crosshair(Loader *loader) {
    this->image = loader->get("crosshair");
}


void Crosshair::create(SDL_Renderer *renderer) {
    int iW, iH;
    SDL_QueryTexture(this->image, NULL, NULL, &iW, &iH);
    int x = WIDTH / 2 - iW / 2;
    int y = HEIGHT / 2 - iH / 2;
    this->applySurface(x, y, this->image, renderer );
}

void Crosshair::applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend, tex, NULL, &pos);
}

void Crosshair::render(int x, int y, SDL_Renderer *renderer, int isRight) {
    SDL_Rect mouse_RECT = { x-15, y-15, 30, 30 };
    SDL_RenderCopyEx(renderer, this->image, NULL, &mouse_RECT, 0, NULL, isRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);
}