#include <SDL2/SDL.h>

#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

class RenderObject {
    public:
        virtual void render(SDL_Renderer* renderer) = 0;
        virtual ~RenderObject() = default;
};

#endif