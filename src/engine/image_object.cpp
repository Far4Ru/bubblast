#include "engine/image_object.hpp"

ImageObject::ImageObject() {

}

ImageObject::~ImageObject() {
    SDL_DestroyTexture(texture);
}

bool ImageObject::load(SDL_Renderer* renderer) {
    SDL_Surface* temp_surf = NULL;
    temp_surf = IMG_Load("assets/wizard.png");
    if (temp_surf == NULL) {
        std::cout << "Can't load image: " << IMG_GetError() << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, temp_surf);

    if (texture == NULL) {
        std::cout << "Can't create texture from surface: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(temp_surf);
    
    return true;
}

void ImageObject::turnLeft() {
    flipType = SDL_FLIP_HORIZONTAL;
}

void ImageObject::turnRight() {
    flipType = SDL_FLIP_NONE;
}

void ImageObject::render(SDL_Renderer* renderer) {
    SDL_Rect rect1 = {x, y, width * scale, height * scale};
    // SDL_RenderCopy(renderer, texture, NULL, &rect1);
    SDL_RenderCopyEx(renderer, texture, NULL, &rect1, 0, NULL, flipType);
}
