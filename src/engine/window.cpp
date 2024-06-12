#include "engine/window.hpp"

Window::Window() {
    //
}

int Window::create() {
    this->core = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (this->core == NULL) {
        SDL_Log(SDL_ERROR, SDL_GetError());
        return 1;
    }
    return 0;
}

SDL_Window* Window::get() {
    return this->core;
}

Window::~Window() {
    SDL_DestroyWindow(this->core);
}