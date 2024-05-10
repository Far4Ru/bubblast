#include <iostream>
#include <SDL2/SDL.h>
#include "game/components/crosshair.hpp"
#include <math.h>
#include <game/loader.hpp>
#include "game/components/utils/image_base.hpp"

Crosshair::Crosshair(Loader *loader) {
    this->image = loader->get("crosshair");
}


void Crosshair::create(SDL_Renderer *renderer) {
    int iW, iH;
    SDL_QueryTexture(this->image, NULL, NULL, &iW, &iH);
    int x = WIDTH / 2 - iW / 2;
    int y = HEIGHT / 2 - iH / 2;
    this->render(x, y, this->image, renderer );
}

void Crosshair::render(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend, tex, NULL, &pos);
}