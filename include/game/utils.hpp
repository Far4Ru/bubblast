#include <SDL2/SDL.h>
#include <iostream>

class Utils {
    public:
        Utils();
        void calc(SDL_FPoint* first, SDL_FPoint* second, SDL_FPoint* velocity);
};
