#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>

/**
 * 
*/
class Event {
    public:
        Event();
    private:
        SDL_Event core;
};