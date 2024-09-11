#include "engine/window.hpp"

Window::Window() {
    create();
}

int Window::create() {
    window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        SDL_Log(GAME_ERROR_WINDOW_CREATE);
        // SDL_Log(SDL_GetError());
        return 1;
    }
    return 0;
}

SDL_Window* Window::get() {
    return window;
}

void Window::fill() {
    screenSurface = SDL_GetWindowSurface(get());
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));
}

Window::~Window() {
    SDL_FreeSurface(screenSurface);
    SDL_DestroyWindow(window);
}

void Window::set_fullscreen(bool value) {
    if (value) {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    } else {
        SDL_SetWindowFullscreen(window, 0);
    }
}

void Window::resize() {
    SDL_GetWindowSize(window, &width, &height);
    fill();
    SDL_UpdateWindowSurface(window);
}
