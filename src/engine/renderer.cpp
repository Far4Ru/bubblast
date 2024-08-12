#include "engine/renderer.hpp"

Renderer::Renderer() {
    window = new Window();

    renderer = SDL_CreateRenderer(window->get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        std::cout << "Can't create renderer: " << SDL_GetError() << std::endl;
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    fps = new FPS();
}

Renderer::~Renderer() {
    loader->~Loader();
    image->~ImageObject();
    window->~Window();
}

void Renderer::keyDown() {
    if (keyboard_state_array[SDL_SCANCODE_UP] || keyboard_state_array[SDL_SCANCODE_W]) {
        image->y -= 10;
    }
    if (keyboard_state_array[SDL_SCANCODE_DOWN] || keyboard_state_array[SDL_SCANCODE_S]) {
        image->y += 10;
    }
    if (keyboard_state_array[SDL_SCANCODE_LEFT] || keyboard_state_array[SDL_SCANCODE_A]) {
        image->x -= 10;
        image->turnLeft();
    }
    if (keyboard_state_array[SDL_SCANCODE_RIGHT] || keyboard_state_array[SDL_SCANCODE_D]) {
        image->x += 10;
        image->turnRight();
    }
    if (keyboard_state_array[SDL_SCANCODE_SPACE]) {
        Mix_PlayChannel(-1, loader->getChunk("BubbleSpell"), 0);
    }
    if (keyboard_state_array[SDL_SCANCODE_1]) {
        Mix_PauseMusic();
    }
    if (keyboard_state_array[SDL_SCANCODE_2]) {
        Mix_ResumeMusic();
    }
}

void Renderer::start() {
    window->fill();
    load();
    Mix_PlayMusic(loader->getMusic("PositiveEnergy"), -1);
}

void Renderer::render() {
    if (fps->tick()) {
        keyDown();
        SDL_SetRenderDrawColor(renderer, 0xFf, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        // SDL_RenderFillRect(renderer, &rect1);
        for (int i = 10; i <= 640-10; i +=4 ) {
            SDL_RenderDrawPoint(renderer, i, 90);
        }
        SDL_RenderDrawLine(renderer, 10, 70, 100, 70);
        
        // text->setText(fps->get() + " FPS. Mouse:" + std::to_string(x) + ":" + std::to_string(y));
        for (RenderObject* render_object : render_queue) {
            render_object->render(renderer);
        }

        SDL_GetMouseState(&x,&y);
        SDL_RenderPresent(renderer);
    }
}

bool Renderer::load() {
    loader = new Loader();
    image = new ImageObject();
    image->load(renderer, loader->getImage("wizard"));
    render_queue.push_back(image);
    text = new TextObject();
    text->setText("Text");
    text->setFont(loader->getFont("WinterCat"));
    render_queue.push_back(text);
    return true;
}
