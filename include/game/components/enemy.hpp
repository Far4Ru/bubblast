#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "game/loader.hpp"
// #include "game/components/utils/image_base.hpp"

/**
 * 
*/
class Enemy {
    public:
        Enemy(Loader *loader);
        void create(SDL_Renderer *renderer);
        void render(int x, int y, SDL_Renderer *renderer);
    private:
        SDL_Texture* image;
        void applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
};