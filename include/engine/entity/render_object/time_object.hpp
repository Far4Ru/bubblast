#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "render_object.hpp"

class TimeObject : public RenderObject {
    public:
        TimeObject();
        ~TimeObject();
        void destroy();

        void render(SDL_Renderer* renderer);
        bool load(SDL_Renderer* renderer, SDL_Surface* imageSurface);
        void process();
        void setProcess(std::function<void()> func);
    private:
        std::function<void()> process_function;
};
