#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.hpp"

class Renderer {
    public:
        Renderer();
        ~Renderer();

        void render();
        bool load();
        void start();

        Window* window;
    private:
        SDL_Surface* screen_surface = NULL;
        SDL_Texture* flower = NULL;
        SDL_Renderer* renderer = NULL;
};