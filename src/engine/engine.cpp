#include "engine/engine.hpp"

Engine::Engine() {
    this->init();
}

void Engine::start() {
    renderer->start();

    SDL_Event e;
    bool resized = true;

    while (true) {
        fps->start();
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_QUIT:
                    active = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouse->clicked = true;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_f:
                            fullScreen = !fullScreen;
                            if(fullScreen){
                                SDL_SetWindowFullscreen(renderer->window->get(), SDL_WINDOW_FULLSCREEN);
                            }
                            else{
                                SDL_SetWindowFullscreen(renderer->window->get(), 0);
                            }
                            break;
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
        game_area->resize(renderer->get(), renderer->window);
        renderer->setScale(game_area->scale);
        scene->process();
        keyboard->process();
        mouse->process();
        if (!active) {
            close();
            return;
        }
        collision->process();
        camera->process();
        renderer->render();
        fps->end();
    }
}

void Engine::close() {
    this->~Engine();
}

void Engine::setFullscreen(bool value) {
    if (value) {
        SDL_SetWindowFullscreen(renderer->window->get(), SDL_WINDOW_FULLSCREEN);
    } else {
        SDL_SetWindowFullscreen(renderer->window->get(), 0);
    }
    fullScreen = value;
}

bool Engine::isFullscreen() {
    return fullScreen;
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
    game_area = new GameAreaManager();
    scene = new SceneManager();

    return 0;
}

Engine::~Engine() {
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
