#pragma once
#include <iostream>
#include <SDL2/SDL.h>

/**
 * This class is responsible for the background
*/
class Background {
    public:
        Background();
    private:
        SDL_Texture* background;
};