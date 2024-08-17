#include "engine/render_object/text_object.hpp"

TextObject::TextObject() {

}

TextObject::~TextObject() {

}

void TextObject::setText(std::string text) {
    this->text = text;
}

void TextObject::setFont(TTF_Font* font) {
    this->font = font;
}

void TextObject::process() {
    if (process_function) {
        process_function();
    }
}

void TextObject::destroy() {
    this->~TextObject();
}

void TextObject::setProcess(std::function<void()> func) {
    process_function = func;
}

void TextObject::render(SDL_Renderer* renderer) {
    textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    mTexture =  SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect abcPosition = { x, y, textSurface->w, textSurface->h };
    SDL_RenderCopy(renderer, mTexture, NULL, &abcPosition);
}
