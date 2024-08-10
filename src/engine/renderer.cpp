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
    image->~ImageObject();
    window->~Window();
}

void Renderer::start() {
    /** surface */
    screen_surface = SDL_GetWindowSurface(window->get());
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 255, 255, 255));

    load();
}

void Renderer::render() {
    SDL_SetRenderDrawColor(renderer, 0xFf, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    // SDL_RenderFillRect(renderer, &rect1);
    for (int i = 10; i <= 640-10; i +=4 ) {
        SDL_RenderDrawPoint(renderer, i, 90);
    }
    SDL_RenderDrawLine(renderer, 10, 70, 100, 70);
    image->render(renderer);
    SDL_RenderPresent(renderer);
}

bool Renderer::load() {
    image = new ImageObject();
    image->load(renderer);

    return true;
}
