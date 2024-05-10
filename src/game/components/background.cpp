#include <iostream>
#include <SDL2/SDL.h>
#include "game/components/background.hpp"
#include <math.h>
#include "game/loader.hpp"
#include "game/components/utils/image_base.hpp"

Background::Background(Loader *loader) {
    this->image = loader->get("background");
}

void Background::create(SDL_Renderer *renderer) {
    int bW, bH;
    SDL_QueryTexture(this->image, NULL, NULL, &bW, &bH);
    this->render(0, 0, this->image, renderer);
}

void Background::render(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend, tex, NULL, &pos);
}