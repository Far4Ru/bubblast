#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class TextObject {
    public:
        TextObject();

        void render(SDL_Renderer* renderer, TTF_Font* font);
        void setText(std::string text);
    private:
        SDL_Texture* mTexture = NULL;
        SDL_Surface* textSurface = NULL;
        SDL_Color textColor = {255,0,0};
        std::string text = "";
};
