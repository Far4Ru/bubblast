#include <SDL2/SDL.h>
#include <iostream>
#include "config/config.hpp"

class Window {
    public:
        Window();
        ~Window();

        SDL_Window* get();
        int create();
        void fill();
        void resize();
        int width;
        int height;
    private:
        SDL_Surface* screenSurface = NULL;
        SDL_Window *window;
};