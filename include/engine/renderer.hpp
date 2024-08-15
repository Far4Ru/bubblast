#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#ifndef RENDERER_H
#define RENDERER_H

#include "window.hpp"
#include "engine/image_object.hpp"
#include "engine/fps.hpp"
#include "engine/text_object.hpp"
#include "engine/loader/loader.hpp"

class Renderer {
    public:
        Renderer();
        ~Renderer();

        void render();
        bool load();
        void start();
        void keyDown();
        void add(RenderObject* object);
        SDL_Renderer* get();

        Window* window;
    private:
        const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
        ImageObject* image = NULL;
        SDL_Renderer* renderer = NULL;
        TextObject* text = NULL;
        FPS* fps = NULL;
        int x = 0, y = 0;
        Loader* loader;
        std::vector<RenderObject*> render_queue;
};

#endif