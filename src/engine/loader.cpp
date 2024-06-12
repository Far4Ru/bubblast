#include "engine/loader.hpp"

Loader::Loader(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

void Loader::start() {
    this->images = new LoadedImage[5];
    this->images[0].name = "background";
    this->images[1].name = "player";
    this->images[2].name = "crosshair";
    this->images[3].name = "bullet";
    this->images[4].name = "enemy";
    this->loadImages();
}

int Loader::loadImages() {
    for (int i = 0; i < 5; i++) {
        this->images[i].texture = this->loadImage("assets/" + this->images[i].name + ".bmp", this->renderer );
        if (this->images[i].texture == nullptr) {
            return 4;
        }
    }
    return 0;
}

SDL_Texture* Loader::loadImage(std::string file, SDL_Renderer* renderer){
    SDL_Surface *loadedImage = nullptr;
    SDL_Texture *texture = nullptr;
        loadedImage = SDL_LoadBMP(file.c_str());
    if (loadedImage != nullptr){
        texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
        std::cout << SDL_GetError() << std::endl;
    return texture;
}

SDL_Texture* Loader::get(std::string name) {
    for (int i = 0; i < 5; i++) {
        if (this->images[i].name == name) {
            return this->images[i].texture;
        }
    }
}

void Loader::destroy() {
    for (int i = 0; i < 5; i++) {
        SDL_DestroyTexture(this->images[i].texture);
    }
}