#include "engine/loader/loader.hpp"

Loader::Loader() {
    fontLoader = new FontLoader();
    soundLoader = new SoundLoader();
    imageLoader = new ImageLoader();
}

Loader::~Loader() {
    imageLoader->~ImageLoader();
}

TTF_Font* Loader::getFont(std::string font) {
    return fontLoader->get(font);
}

SDL_Surface* Loader::getImage(std::string image) {
    return imageLoader->get(image);
}

Mix_Music* Loader::getMusic(std::string music) {
    return soundLoader->getMusic(music);
}

Mix_Chunk* Loader::getChunk(std::string chunk) {
    return soundLoader->getChunk(chunk);
}