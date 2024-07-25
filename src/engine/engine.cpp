#include "engine/engine.hpp"

Engine::Engine() {
    this->init();
    this->window = new Window();
    this->window->create();

    /** surface */
    SDL_Surface* screen_surface = NULL;
    screen_surface = SDL_GetWindowSurface(this->window->get());
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 255, 255, 255));

    SDL_UpdateWindowSurface(this->window->get());

    SDL_Delay(2000);
}

int Engine::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    return 0;
}

Engine::~Engine() {
    SDL_Quit();
}