#include "engine/engine.hpp"

Engine::Engine() {
    this->init();
}

void Engine::start() {
    renderer->start();

    SDL_Event e;
    bool resized = false;

    while (true) {
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_QUIT:
                    close();
                    return;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            close();
                            return;
                    }
                    break;
                case SDL_WINDOWEVENT:
                    switch(e.window.event) {
                        case SDL_WINDOWEVENT_RESIZED:
                        case SDL_WINDOWEVENT_SIZE_CHANGED:
                            resized = true;
                            break;
                    }
                    break;
            }
        }

        if (resized) {
            resized = false;
            renderer->window->resize();
        }
        fps->start();
        keyboard->process();
        mouse->process();
        collision->process();
        camera->process();
        renderer->render();
        fps->end();
    }
}

void Engine::close() {
    this->~Engine();
}

int Engine::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    renderer = new Renderer();

    int flags = IMG_INIT_PNG;
    if (!(IMG_Init(flags) & flags)) {
        std::cout << "Can't init image: " << IMG_GetError() << std::endl;
        return 1;
    }

    TTF_Init();
    
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT,2,2048);
    loader = new Loader();
    sound = new SoundManager(loader);
    keyboard = new KeyboardManager();
    fps = new FPS();
    mouse = new MouseManager();
    add = new ObjectFactory(renderer, loader);
    axis_computing = new AxisComputing();
    collision = new CollisionManager();
    camera = new CameraManager();

    return 0;
}

Engine::~Engine() {
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
