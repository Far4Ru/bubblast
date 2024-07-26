#include "engine/renderer.hpp"

Renderer::Renderer() {
    this->window = new Window();
    this->window->create();

    this->renderer = SDL_CreateRenderer(this->window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->renderer == NULL) {
        std::cout << "Can't create renderer: " << SDL_GetError() << std::endl;
    }
    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

Renderer::~Renderer() {
    SDL_FreeSurface(this->screen_surface);
    SDL_DestroyTexture(this->flower);
    this->window->~Window();
}

void Renderer::start() {
    /** surface */
    this->screen_surface = SDL_GetWindowSurface(this->window->get());
    SDL_FillRect(this->screen_surface, NULL, SDL_MapRGB(this->screen_surface->format, 255, 255, 255));

    load();
}

void Renderer::render() {
    SDL_RenderClear(this->renderer);
    SDL_RenderCopy(this->renderer, this->flower, NULL, NULL);
    SDL_RenderPresent(this->renderer);

}

bool Renderer::load() {

    SDL_Surface * temp_surf = NULL;
    temp_surf = IMG_Load("assets/wizard.png");
    if (temp_surf == NULL) {
        std::cout << "Can't load image: " << IMG_GetError() << std::endl;
        return false;
    }

    this->flower = SDL_CreateTextureFromSurface(this->renderer, temp_surf);
    if (this->flower == NULL) {
        std::cout << "Can't create texture from surface: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(temp_surf);

    return true;
}