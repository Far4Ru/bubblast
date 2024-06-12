#include "engine/engine.hpp"

Engine::Engine() {
    this->init();
    this->window->create();
}

int Engine::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
}

Engine::~Engine() {
    SDL_Quit();
}