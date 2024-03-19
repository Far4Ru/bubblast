#include <iostream>
#include <SDL2/SDL.h>
#include "game/game.hpp"
#include "game/background.hpp"
#include "game/loader.hpp"
#include <math.h>

Game::Game() {
    this->init();

    this->createWindow();
    this->createRenderer();
    this->loader = new Loader(this->renderer);
    this->loader->start();
    this->background = this->loader->get("background");
    this->crosshair = this->loader->get("crosshair");
    this->image = this->loader->get("image");

    SDL_RenderClear(this->renderer);

    this->createBackground();
    this->createCrosshair();
    this->createImage();
    
    this->runGameLoop();
    
    this->clear();
    
    SDL_Quit();
}

void Game::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

void Game::runGameLoop() {
    SDL_RenderPresent(this->renderer );
    Uint32 frameStart = 0;
    Uint32 frameTimeToComplete = -1;
    double frameLength;

    Uint64 startTime;
    Uint64 endTime;
    int x = 0, y = 0;
    int flag = 0;
    SDL_StartTextInput();
    const Uint8* currentKeyState;
    int isRight = 1;

    int mouseX, mouseY;
    while (true) {
        // Start FPS count
        frameStart = SDL_GetTicks();
        startTime = SDL_GetPerformanceCounter();
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
        SDL_Rect background_RECT = { x + -200, y + -200, 1400, 900 };
        SDL_RenderCopyEx(this->renderer,this->background,NULL,&background_RECT, 0, NULL, SDL_FLIP_NONE);
        int newX = std::floor(x / 1400);
        int newY = std::floor(y / 900);
        background_RECT = { newX * 1400 + -200 - newX * 1400, y + -200, 1400, 900 };
        SDL_RenderCopyEx(this->renderer,this->background,NULL,&background_RECT, 0, NULL, SDL_FLIP_NONE);
        background_RECT = { x + -200, y + -200 - newY * 900, 1400, 900 };
        SDL_RenderCopyEx(this->renderer,this->background,NULL,&background_RECT, 0, NULL, SDL_FLIP_NONE);
        SDL_Rect player_RECT = { 400, 300, 100, 100 };
        SDL_RenderCopyEx(this->renderer, this->image, NULL, &player_RECT, 0, NULL, isRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);
        SDL_Rect mouse_RECT = { mouseX-15, mouseY-15, 30, 30 };
        SDL_RenderCopyEx(this->renderer, this->crosshair, NULL, &mouse_RECT, 0, NULL, isRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);
        SDL_RenderPresent(this->renderer);
        
        // End FPS count
        endTime = SDL_GetPerformanceCounter();
        frameLength = (endTime - startTime) / static_cast<double>(SDL_GetPerformanceFrequency());
        
        // Delay to FPS cap
        frameTimeToComplete = SDL_GetTicks() - frameStart;
        if (1000 / FPS > frameTimeToComplete) {
            SDL_Delay((1000 / FPS) - frameTimeToComplete);
        }
        if (!(1000 / FPS > frameTimeToComplete)) {
            printf("DID NOT FINISH IN TIME\n");
        }
    }
}

void Game::applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend, tex, NULL, &pos);
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

void Game::createBackground() {
    int bW, bH;
    SDL_QueryTexture(this->background, NULL, NULL, &bW, &bH);
    this->applySurface(0, 0, this->background, this->renderer );
}

void Game::createImage() {
    int iW, iH;
    SDL_QueryTexture(this->image, NULL, NULL, &iW, &iH);
    int x = WIDTH / 2 - iW / 2;
    int y = HEIGHT / 2 - iH / 2;
    this->applySurface(x, y, this->image, this->renderer );
}

void Game::createCrosshair() {
    int iW, iH;
    SDL_QueryTexture(this->crosshair, NULL, NULL, &iW, &iH);
    int x = WIDTH / 2 - iW / 2;
    int y = HEIGHT / 2 - iH / 2;
    this->applySurface(x, y, this->crosshair, this->renderer );
}

void Game::clear() {
    this->loader->destroy();
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}
