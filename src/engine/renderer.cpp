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
        Mix_PlayChannel(-1,fireMusic,0);
    }
    if (keyboard_state_array[SDL_SCANCODE_1]) {
        Mix_PauseMusic();
    }
    if (keyboard_state_array[SDL_SCANCODE_2]) {
        Mix_ResumeMusic();
    }
}

void Renderer::start() {
    /** surface */
    screen_surface = SDL_GetWindowSurface(window->get());
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 255, 255, 255));

    load();
    Mix_PlayMusic(music,-1);
}

void Renderer::render() {

    Uint32 a = SDL_GetTicks();
    Uint32 delta = a - b;

    if (delta > 1000 / 60) {
        b = a;
        keyDown();
        SDL_SetRenderDrawColor(renderer, 0xFf, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        // SDL_RenderFillRect(renderer, &rect1);
        for (int i = 10; i <= 640-10; i +=4 ) {
            SDL_RenderDrawPoint(renderer, i, 90);
        }
        SDL_RenderDrawLine(renderer, 10, 70, 100, 70);
        image->render(renderer);

        SDL_GetMouseState(&x,&y);
        
        textSurface = TTF_RenderText_Solid(rFont, (std::to_string(1000 / delta) + " FPS. Mouse:" + std::to_string(x) + ":" + std::to_string(y)).c_str(), textColor);
        mTexture =  SDL_CreateTextureFromSurface(renderer ,textSurface);
        SDL_Rect abcPosition = {210,0,textSurface->w,textSurface->h};
        SDL_RenderCopy(renderer,mTexture,NULL,&abcPosition);
        SDL_RenderPresent(renderer);
    }
}

bool Renderer::load() {
    image = new ImageObject();
    image->load(renderer);
  
    rFont = TTF_OpenFont("assets/fonts/WinterCat.ttf",52);

    fireMusic = Mix_LoadWAV("assets/sounds/BubbleSpell.wav");
    music = Mix_LoadMUS("assets/sounds/PositiveEnergy.wav");

    return true;
}
