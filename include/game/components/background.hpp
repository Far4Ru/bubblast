#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <game/components/utils/image_base.hpp>
#include "game/loader.hpp"

/**
 * This class is responsible for the background
*/
class Background {
    public:
        Background(Loader *loader);
        void create(SDL_Renderer *renderer);
    private:
        SDL_Texture* image;
        void render(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
};