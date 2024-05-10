#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "game/loader.hpp"
#include "game/components/utils/image_base.hpp"

class Crosshair {
    public:
        Crosshair(Loader *loader);
        void create(SDL_Renderer *renderer);
    private:
        SDL_Texture* image;
        void render(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
};