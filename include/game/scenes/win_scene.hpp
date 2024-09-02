#ifndef WIN_SCENE_H
#define WIN_SCENE_H

#include "engine/engine.hpp"
#include "game/scenes/scene_base.hpp"

class WinScene : public SceneBase {
    public:
        WinScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
};

#endif
