#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "window.hpp"
#include "engine/image_object.hpp"

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
        SDL_Texture* mTexture = NULL;
        SDL_Surface* textSurface = NULL;
        Uint32 b = 0;
        TTF_Font* rFont = NULL;
        SDL_Color textColor = {255,0,0};
        Mix_Chunk* fireMusic = NULL;
        Mix_Music* music = NULL;
};