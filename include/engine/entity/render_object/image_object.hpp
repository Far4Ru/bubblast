#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#ifndef IMAGE_OBJECT_H
#define IMAGE_OBJECT_H

#include "render_object.hpp"

class ImageObject : public RenderObject {
    public:
        ImageObject();
        ~ImageObject();
        void destroy();

        float x = 0;
        float y = 0;
        int width = 100;
        int height = 100;
        float scale = 1;
        SDL_Rect crop;

        void turnLeft();
        void turnRight();

        void render(SDL_Renderer* renderer);
        bool load(SDL_Renderer* renderer, SDL_Surface* imageSurface);
        void process();
        void setProcess(std::function<void()> func);
        void setScale(float scale);
        void setOffset(int x, int y);
    private:
        int offsetX = 0;
        int offsetY = 0;
        SDL_RendererFlip flipType = SDL_FLIP_NONE;
        float render_scale = 0;
        SDL_Texture* texture = NULL;
        std::function<void()> process_function;
};

#endif
