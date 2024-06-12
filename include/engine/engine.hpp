#include <SDL2/SDL.h>

#include "renderer.hpp"
#include "window.hpp"
#include "fps.hpp"
#include "loader.hpp"
#include "input.hpp"

class Engine {
    public:
        Engine();
        ~Engine();

        Input* input;
        Loader* loader;
        FPS* fps;
        Renderer* renderer;
        Window* window;
    private:
        int init();
};