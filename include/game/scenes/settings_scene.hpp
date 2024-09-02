#ifndef SETTINGS_SCENE_H
#define SETTINGS_SCENE_H

#include "engine/engine.hpp"
#include "game/scenes/scene_base.hpp"

class SettingsScene : public SceneBase {
    public:
        SettingsScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
};

#endif
