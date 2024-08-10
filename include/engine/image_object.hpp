#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class ImageObject {
    public:
        ImageObject();
        ~ImageObject();

        void render(SDL_Renderer* renderer);
        bool setTexture(SDL_Renderer* renderer);
    private:
        SDL_Texture* texture = NULL;
};
