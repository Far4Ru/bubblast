#include "engine/engine.hpp"

Engine::Engine() {
    this->init();

    /** surface */
    this->screen_surface = SDL_GetWindowSurface(this->window->get());
    SDL_FillRect(this->screen_surface, NULL, SDL_MapRGB(this->screen_surface->format, 255, 255, 255));
    this->load();

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

        SDL_RenderClear(this->ren);
        SDL_RenderCopy(this->ren, this->flower, NULL, NULL);
        SDL_RenderPresent(this->ren);
    }

    this->~Engine();
}

bool Engine::load() {
    SDL_Surface * temp_surf = NULL;
    temp_surf = IMG_Load("assets/wizard.png");
    if (temp_surf == NULL) {
        std::cout << "Can't load image: " << IMG_GetError() << std::endl;
        return false;
    }

    this->flower = SDL_CreateTextureFromSurface(this->ren, temp_surf);
    if (this->flower == NULL) {
        std::cout << "Can't create texture from surface: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(temp_surf);

    return true;
}

int Engine::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    this->window = new Window();
    this->window->create();

    this->ren = SDL_CreateRenderer(this->window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->ren == NULL) {
        std::cout << "Can't create renderer: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_SetRenderDrawColor(this->ren, 0xFF, 0xFF, 0xFF, 0xFF);

    int flags = IMG_INIT_PNG;
    if ( !( IMG_Init( flags ) & flags ) ) {
        std::cout << "Can't init image: " << IMG_GetError() << std::endl;
        return 1;
    }
    return 0;
}

Engine::~Engine() {
    SDL_DestroyTexture(this->flower);
    
    SDL_FreeSurface(this->screen_surface);
    this->window->~Window();
    SDL_Quit();
    IMG_Quit();
}