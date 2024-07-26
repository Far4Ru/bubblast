#include "engine/renderer.hpp"

Renderer::Renderer() {
    window = new Window();

    renderer = SDL_CreateRenderer(window->get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        std::cout << "Can't create renderer: " << SDL_GetError() << std::endl;
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

Renderer::~Renderer() {
    SDL_FreeSurface(screen_surface);
    SDL_DestroyTexture(flower);
    window->~Window();
}

void Renderer::start() {
    /** surface */
    screen_surface = SDL_GetWindowSurface(window->get());
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 255, 255, 255));

    load();
}

void Renderer::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, flower, NULL, NULL);
    SDL_RenderPresent(renderer);

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