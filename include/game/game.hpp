#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "game/components/background.hpp"
#include "game/components/crosshair.hpp"
#include "game/components/player.hpp"
#include "game/loader.hpp"
#include "game/fps.hpp"

#define WIDTH 800
#define HEIGHT 600

class Game {
    public:
        Game();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        Loader *loader;
        SDL_Event windowEvent;

        Background *background;
        Player *player;
        Crosshair *crosshair;
        FPS *fps;

        void init();
        void runGameLoop();
        int createWindow();
        int createRenderer();
        void clear();
};