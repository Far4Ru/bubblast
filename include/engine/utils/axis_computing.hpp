#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

class AxisComputing {
    public:
        AxisComputing();
        void computeVelocity(SDL_FPoint* first, SDL_FPoint* second, SDL_FPoint* velocity);
};
