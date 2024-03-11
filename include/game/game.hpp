#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "game/background.hpp"
#include "game/loader.hpp"

#define WIDTH 800
#define HEIGHT 600
#define FPS 60

class Game {
    public:
        Game();
    private:
        Loader *loader;
        Background *backgroundClass;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *background;
        SDL_Texture *image;
        SDL_Texture *crosshair;
        SDL_Event windowEvent;

        void init();
        void runGameLoop();
        void applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
        int createWindow();
        int createRenderer();
        void createBackground();
        void createImage();
        void createCrosshair();
        void clear();
};