#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.hpp"
#include "engine/image_object.hpp"

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
        ImageObject* image = NULL;
        SDL_Renderer* renderer = NULL;
};