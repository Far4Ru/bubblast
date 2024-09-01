#ifndef SETTINGS_SCENE_H
#define SETTINGS_SCENE_H

#include "engine/engine.hpp"

class SettingsScene {
    public:
        SettingsScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
};

#endif
