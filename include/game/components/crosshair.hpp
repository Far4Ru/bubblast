#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "game/loader.hpp"
// #include "game/components/utils/image_base.hpp"

#define WIDTH 800
#define HEIGHT 600

class Crosshair {
    public:
        Crosshair(Loader *loader);
        void create(SDL_Renderer *renderer);
        void render(int x, int y, SDL_Renderer *renderer, int isRight);
    private:
        SDL_Texture* image;
        void applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
};