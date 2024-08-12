#include "engine/text_object.hpp"

TextObject::TextObject() {

}

void TextObject::setText(std::string text) {
    this->text = text;
}

void TextObject::setFont(TTF_Font* font) {
    this->font = font;
}

void TextObject::render(SDL_Renderer* renderer) {
    textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    mTexture =  SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect abcPosition = { 210, 0, textSurface->w, textSurface->h };
    SDL_RenderCopy(renderer, mTexture, NULL, &abcPosition);
}
