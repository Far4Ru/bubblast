#include <SDL2/SDL.h>
#include <iostream>
#include "config/config.hpp"

class Window {
    public:
        Window();
        SDL_Window* get();
        int create();
    private:
        SDL_Window *core;
};