#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "window.hpp"
#include "engine/image_object.hpp"
#include "engine/image_loader.hpp"
#include "engine/fps.hpp"
#include "engine/text_object.hpp"

class Renderer {
    public:
        Renderer();
        ~Renderer();

        void render();
        bool load();
        void start();
        void keyDown();

        Window* window;
    private:
        const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
        SDL_Surface* screen_surface = NULL;
        ImageObject* image = NULL;
        SDL_Renderer* renderer = NULL;
        TextObject* text = NULL;
        TTF_Font* rFont = NULL;
        Mix_Chunk* fireMusic = NULL;
        Mix_Music* music = NULL;
        FPS* fps = NULL;
        int x=0,y=0;
        ImageLoader* imageLoader = NULL;
};