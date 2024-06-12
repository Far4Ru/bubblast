#include <SDL2/SDL.h>

#include "window.hpp"

class Engine {
    public:
        Engine();
        ~Engine();

        Window* window;
    private:
        int init();
};