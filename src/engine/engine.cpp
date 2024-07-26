#include "engine/engine.hpp"

Engine::Engine() {
    this->init();
}

void Engine::start() {
    renderer->start();

    SDL_Event e;

    bool run = true;
    while (run) {
        while(SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                run = false;
            }
            else if( e.type == SDL_KEYDOWN ) {
                switch( e.key.keysym.sym ) {
                    case SDLK_ESCAPE:
                        run = false;
                        break;
                }
            }
        }

        renderer->render();
    }

    this->~Engine();
}

int Engine::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    renderer = new Renderer();

    int flags = IMG_INIT_PNG;
    if ( !( IMG_Init( flags ) & flags ) ) {
        std::cout << "Can't init image: " << IMG_GetError() << std::endl;
        return 1;
    }
    return 0;
}

Engine::~Engine() {
    SDL_Quit();
    IMG_Quit();
}