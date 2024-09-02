#ifndef LOSE_SCENE_H
#define LOSE_SCENE_H

#include "engine/engine.hpp"
#include "game/scenes/scene_base.hpp"

class LoseScene : public SceneBase {
    public:
        LoseScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
};

#endif
