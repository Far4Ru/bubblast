#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#ifndef ENGINE_H
#define ENGINE_H

#include "engine/renderer.hpp"
#include "engine/factory/object_factory.hpp"
#include "engine/loader/loader.hpp"
#include "engine/manager/sound_manager.hpp"
#include "engine/manager/keyboard_manager.hpp"
#include "engine/manager/fps_manager.hpp"
#include "engine/manager/mouse_manager.hpp"
#include "engine/utils/axis_computing.hpp"
#include "engine/collision/collision_manager.hpp"

class Engine {
    public:
        Engine();
        ~Engine();

        void start();
        ObjectFactory* add;
        SoundManager* sound;
        KeyboardManager* keyboard;
        FPS* fps;
        MouseManager* mouse;
        AxisComputing* axis_computing;
        CollisionManager* collision;
    private:
        Renderer* renderer;
        Loader* loader;
        int init();
        void close();
};

extern Engine* engine;

#endif
