#include "engine/window.hpp"

Window::Window() {
    create();
}

int Window::create() {
    window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
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
    /** surface */
    screenSurface = SDL_GetWindowSurface(get());
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 255, 255));
}

Window::~Window() {
    SDL_FreeSurface(screenSurface);
    SDL_DestroyWindow(window);
}

void Window::resize() {
    SDL_GetWindowSize(window, &width, &height);
    fill();
    SDL_UpdateWindowSurface(window);

    // TODO: - use screen width and height
    // SDL_Log("%d %d", width, height);
}
