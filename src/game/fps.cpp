#include <iostream>
#include <SDL2/SDL.h>
#include "game/fps.hpp"
#include <math.h>

FPS::FPS() {
}
void FPS::start() {
    this->frameStart = SDL_GetTicks();
    this->startTime = SDL_GetPerformanceCounter();
}
void FPS::end() {
    // End FPS count
    this->endTime = SDL_GetPerformanceCounter();
    this->frameLength = (this->endTime - this->startTime) / static_cast<double>(SDL_GetPerformanceFrequency());
    
    // Delay to FPS cap
    this->frameTimeToComplete = SDL_GetTicks() - this->frameStart;
    if (1000 / MAX_FPS > this->frameTimeToComplete) {
        SDL_Delay((1000 / MAX_FPS) - this->frameTimeToComplete);
    }
    if (!(1000 / MAX_FPS > this->frameTimeToComplete)) {
        printf("DID NOT FINISH IN TIME\n");
    }
}