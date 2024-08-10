#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class ImageObject {
    public:
        ImageObject();
        ~ImageObject();

        int x = 0;
        int y = 0;
        int width = 50;
        int height = 50;
        int scale = 1;

        void render(SDL_Renderer* renderer);
        bool load(SDL_Renderer* renderer);
    private:
        SDL_Texture* texture = NULL;
};
