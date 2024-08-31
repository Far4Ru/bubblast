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
#include "engine/manager/camera_manager.hpp"
#include "engine/manager/collision_manager.hpp"
#include "engine/manager/game_area_manager.hpp"
#include "engine/utils/axis_computing.hpp"

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
        CameraManager* camera;
        CollisionManager* collision;
        GameAreaManager* game_area;

        AxisComputing* axis_computing;
        Renderer* renderer;
        bool active = true;
    private:
        Loader* loader;
        int init();
        void close();
};

extern Engine* engine;

#endif
