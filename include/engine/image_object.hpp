#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class ImageObject {
    public:
        ImageObject();
        ~ImageObject();

        int x = 0;
        int y = 0;
        int width = 100;
        int height = 100;
        int scale = 1;

        void turnLeft();
        void turnRight();

        void render(SDL_Renderer* renderer);
        bool load(SDL_Renderer* renderer);
    private:
        SDL_RendererFlip flipType = SDL_FLIP_NONE;
        SDL_Texture* texture = NULL;
};
