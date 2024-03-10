#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "game/background.hpp"

#define WIDTH 800
#define HEIGHT 600

class Game {
    public:
        Game();
    private:
        Background *backgroundClass;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *background;
        SDL_Texture *image;
        SDL_Texture *crosshair;
        SDL_Event windowEvent;

        void init();
        void runGameLoop();
        SDL_Texture *loadImage(std::string file, SDL_Renderer *renderer);
        void applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
        int createWindow();
        int createRenderer();
        int loadImages();
        void createBackground();
        void createImage();
        void createCrosshair();
        void clear();
};