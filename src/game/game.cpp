#include <iostream>
#include <SDL2/SDL.h>
#include "game/game.hpp"

Game::Game() {
    this->init();

    this->createWindow();
    this->createRenderer();
    
    this->loadImages();
    this->createBackground();
    
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
    int fpsCap = 60;
    Uint32 frameTimeToComplete = -1;
    double frameLength;

	Uint64 startTime;
	Uint64 endTime;
    int i = 100;
    int flag = 0;
    while (true) {
        // Start FPS count
		frameStart = SDL_GetTicks();
		startTime = SDL_GetPerformanceCounter();
        
        // Exit event
        if (SDL_PollEvent(&this->windowEvent)) {
            if (SDL_QUIT == this->windowEvent.type) {
                break;
            }
        }

		// Render
        SDL_RenderClear(this->renderer);
        SDL_Rect background_RECT = { -200, (flag ? i++ : i--) -200, 1400, 900 };
        SDL_RenderCopyEx(this->renderer,background,NULL,&background_RECT, 0, NULL, SDL_FLIP_NONE);
        if (i < -50) {
            SDL_Rect player_RECT = { 400, 300, (1 - i * 2) + 100, (1 - i * 2) + 100 };
            SDL_RenderCopyEx(this->renderer, this->image, NULL, &player_RECT, 0, NULL, SDL_FLIP_NONE);
        }
        SDL_RenderPresent(this->renderer);
        
        // End FPS count
        endTime = SDL_GetPerformanceCounter();
		frameLength = (endTime - startTime) / static_cast<double>(SDL_GetPerformanceFrequency());
        
        // Delay to FPS cap
		frameTimeToComplete = SDL_GetTicks() - frameStart;
		if (1000 / fpsCap > frameTimeToComplete) {
			SDL_Delay((1000 / fpsCap) - frameTimeToComplete);
		}
		if (!(1000 / fpsCap > frameTimeToComplete)) {
			printf("DID NOT FINISH IN TIME\n");
		}

        // Reverse animation loop
        if (flag ? i > 100 : i < -100) {
            i = flag ? 100 : -100;
            flag = !flag;
        }
    }
}

SDL_Texture* Game::loadImage(std::string file, SDL_Renderer* renderer){
    SDL_Surface *loadedImage = nullptr;
    SDL_Texture *texture = nullptr;
        loadedImage = SDL_LoadBMP(file.c_str());
    if (loadedImage != nullptr){
        texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
        std::cout << SDL_GetError() << std::endl;
    return texture;
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

int Game::loadImages() {
    this->background = this->loadImage("assets/background.bmp", this->renderer );
    this->image = this->loadImage("assets/image.bmp", this->renderer );
    if (this->background == nullptr || this->image == nullptr) {
        return 4;
    }
    SDL_RenderClear(this->renderer);
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

void Game::clear() {
    SDL_DestroyTexture(this->background);
    SDL_DestroyTexture(this->image);
    SDL_DestroyRenderer(this->renderer );
    SDL_DestroyWindow(this->window);
}
