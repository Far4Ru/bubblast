#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.hpp"

class Engine {
    public:
        Engine();
        ~Engine();

        Window* window;
        void run();
    private:
        SDL_Surface* screen_surface = NULL;
        SDL_Texture* flower = NULL;
        SDL_Renderer* ren = NULL;

        int init();
        bool load();
};