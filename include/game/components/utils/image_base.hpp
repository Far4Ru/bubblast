#pragma once
#include <iostream>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 600

/**
 * This class is responsible for the background
*/
class ImageBase {
    public:
        ImageBase();
    protected:
        SDL_Texture* image;
        void create(SDL_Renderer *renderer);
        void render(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
};