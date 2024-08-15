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
    window->~Window();
}

void Renderer::start() {
    window->fill();
}

void Renderer::render() {
    SDL_RenderClear(renderer);

    for (RenderObject* render_object : render_queue) {
        render_object->process();
        render_object->render(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Renderer::add(RenderObject* object) {
    render_queue.push_back(object);
}

SDL_Renderer* Renderer::get() {
    return renderer;
}
