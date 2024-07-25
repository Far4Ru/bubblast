#include "engine/window.hpp"

Window::Window() {
    //
}

int Window::create() {
    this->window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (this->window == NULL) {
        SDL_Log(GAME_ERROR_WINDOW_CREATE);
        // SDL_Log(SDL_GetError());
        return 1;
    }
    return 0;
}

SDL_Window* Window::get() {
    return this->window;
}

Window::~Window() {
    SDL_DestroyWindow(this->window);
}