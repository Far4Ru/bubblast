#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "render_object.hpp"

class TextObject : public RenderObject {
    public:
        TextObject();

        void render(SDL_Renderer* renderer) override;
        void setText(std::string text);
        void setFont(TTF_Font* font);
    private:
        SDL_Texture* mTexture = NULL;
        SDL_Surface* textSurface = NULL;
        SDL_Color textColor = {255,0,0};
        TTF_Font* font = NULL;
        std::string text = "";
};
