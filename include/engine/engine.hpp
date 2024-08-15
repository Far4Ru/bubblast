#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "engine/renderer.hpp"
#include "object_factory.hpp"
#include "engine/loader/loader.hpp"
#include "engine/sound_manager.hpp"

class Engine {
    public:
        Engine();
        ~Engine();

        void start();
        ObjectFactory* add = NULL;
        SoundManager* sound;
    private:
        Renderer* renderer = NULL;
        Loader* loader;
        int init();
        void close();
};