#include <iostream>
#include <SDL2/SDL.h>
#include "game/game.hpp"
#include "game/components/background.hpp"
#include "game/components/crosshair.hpp"
#include "game/components/player.hpp"
#include "game/loader.hpp"
#include "game/fps.hpp"
#include <math.h>

Game::Game() {
    this->init();

    this->createWindow();
    this->createRenderer();
    this->loader = new Loader(this->renderer);
    this->loader->start();
    this->background = new Background(this->loader);
    this->crosshair = new Crosshair(this->loader);
    this->player = new Player(this->loader);

    this->fps = new FPS();

    SDL_RenderClear(this->renderer);

    this->background->create(this->renderer);
    this->crosshair->create(this->renderer);
    this->player->create(this->renderer);
    
    this->runGameLoop();
    
    this->clear();
    
    SDL_Quit();
}

void Game::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

void Game::runGameLoop() {
    SDL_RenderPresent(this->renderer );
    int x = 0, y = 0;
    int flag = 0;
    SDL_StartTextInput();
    const Uint8* currentKeyState;
    int isRight = 1;

    int mouseX, mouseY;
    while (true) {
        this->fps->start();
        SDL_PumpEvents();
        currentKeyState = SDL_GetKeyboardState(nullptr);
        if (SDL_PollEvent(&this->windowEvent)) {
            if (SDL_QUIT == this->windowEvent.type) {
                // Exit event
                break;
            }
        }
        SDL_GetMouseState(&mouseX, &mouseY);
        // Keyboard event
        SDL_Keycode keycode = this->windowEvent.key.keysym.sym;
        if (currentKeyState[SDL_SCANCODE_W] || currentKeyState[SDL_SCANCODE_UP]) {
            y += 10;
        }
        if (currentKeyState[SDL_SCANCODE_S] || currentKeyState[SDL_SCANCODE_DOWN]) {
            y -= 10;
        }
        if (currentKeyState[SDL_SCANCODE_A] || currentKeyState[SDL_SCANCODE_LEFT]) {
            isRight = 0;
            x += 10;
        }
        if (currentKeyState[SDL_SCANCODE_D] || currentKeyState[SDL_SCANCODE_RIGHT]){
            isRight = 1;
            x -= 10;
        }
        SDL_StopTextInput();
        SDL_ShowCursor(SDL_DISABLE);

        // Render
        SDL_RenderClear(this->renderer);

        this->background->render(x, y, this->renderer);
        this->player->render(this->renderer, isRight);
        this->crosshair->render(mouseX, mouseY, this->renderer, isRight);

        SDL_RenderPresent(this->renderer);
        
        this->fps->end();
    }
}

int Game::createWindow() {
    this->window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (NULL == this->window) {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }
    return 0;
}

int Game::createRenderer() {
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->renderer == nullptr){
        std::cout << SDL_GetError() << std::endl;
        return 2;
    }
    return 0;
}

void Game::clear() {
    this->loader->destroy();
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}
