#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>

struct LoadedImage {
  std::string name;
  SDL_Texture *texture;
};

/**
 * 
*/
class Loader {
    public:
        Loader(SDL_Renderer *renderer);
        void start();
        SDL_Texture* get(std::string);
        void destroy();
    private:
        SDL_Renderer *renderer;
        LoadedImage *images;
        int loadImages();
        SDL_Texture* loadImage(std::string file, SDL_Renderer* renderer);
};