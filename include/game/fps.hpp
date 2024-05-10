#pragma once
#include <iostream>
#include <SDL2/SDL.h>

#define MAX_FPS 60

class FPS {
    public:
        FPS();
        void start();
        void end();
    private:
        Uint32 frameStart = 0;
        Uint32 frameTimeToComplete = -1;
        double frameLength;

        Uint64 startTime;
        Uint64 endTime;
};