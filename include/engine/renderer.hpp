#include <SDL2/SDL.h>
#include <iostream>

class Renderer {
    public:
        Renderer();
    private:
        SDL_Renderer *core;
        int create();
};
