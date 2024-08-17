#include "engine/engine.hpp"
#include <iostream>

class Bullet {
    public:
        Bullet();
    private:
        void calc(SDL_FPoint* first, SDL_FPoint* second, SDL_FPoint* velocity);
};
