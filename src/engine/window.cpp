#include "engine/window.hpp"

Window::Window() {
    create();
}

int Window::create() {
    window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
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
    screen_surface = SDL_GetWindowSurface(get());
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 255, 255, 255));
}

Window::~Window() {
    SDL_FreeSurface(screen_surface);
    SDL_DestroyWindow(window);
}
