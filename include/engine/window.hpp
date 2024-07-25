#include <SDL2/SDL.h>
#include <iostream>
#include "config/config.hpp"

class Window {
    public:
        Window();
        ~Window();
        SDL_Window* get();
        int create();
        SDL_Window *window;
    private:
};