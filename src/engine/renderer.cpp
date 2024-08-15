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
    loader->~Loader();
    image->~ImageObject();
    window->~Window();
}

void Renderer::start() {
    window->fill();
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
    
    for (RenderObject* render_object : render_queue) {
        render_object->process();
        render_object->render(renderer);
    }

    SDL_GetMouseState(&x,&y);
    SDL_RenderPresent(renderer);
}

void Renderer::add(RenderObject* object) {
    render_queue.push_back(object);
}

SDL_Renderer* Renderer::get() {
    return renderer;
}

bool Renderer::load() {
    loader = new Loader();
    image = new ImageObject();
    image->load(renderer, loader->getImage("wizard"));
    add(image);
    text = new TextObject();
    auto textFunc = [&]() {
        // fps->get() + " FPS"
        text->setText("Mouse:" + std::to_string(x) + ":" + std::to_string(y));
    };
    text->setProcess(textFunc);
    text->setFont(loader->getFont("WinterCat"));
    add(text);
    return true;
}
