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
    window->resize();
}

void Renderer::setScale(float scale) {
    for (RenderObject* render_object : render_queue) {
        render_object->setScale(scale);
    }
}

void Renderer::render() {
    SDL_RenderClear(renderer);
    for (RenderObject* render_object : render_queue) {
        if (active) {
            if (render_object->active) {
                render_object->process();
                if (active) {
                    render_object->render(renderer);
                }
            } else if (render_object->to_destroy) {
                remove(render_object);
                render_object->destroy();
            }
        }
    }
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0x00 );

    SDL_RenderPresent(renderer);
}

void Renderer::add(RenderObject* object) {
    active = true;
    render_queue.push_back(object);
}

void Renderer::remove(RenderObject* object) {
    render_queue.erase(std::remove(render_queue.begin(), render_queue.end(), object), render_queue.end());
}

void Renderer::clear() {
    std::vector<RenderObject*>().swap(render_queue);
    active = false;
}

SDL_Renderer* Renderer::get() {
    return renderer;
}
