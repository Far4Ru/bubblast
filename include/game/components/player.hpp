#pragma once
#include <iostream>
#include <SDL2/SDL.h>
// #include "game/components/utils/image_base.hpp"
#include "game/loader.hpp"

#define WIDTH 800
#define HEIGHT 600
/**
 * 
*/
class Player {
    public:
        Player(Loader *loader);
        void create(SDL_Renderer *renderer);
        void render(SDL_Renderer *renderer, int isRight);
    private:
        SDL_Texture* image;
        void applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
};