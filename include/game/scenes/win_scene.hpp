#ifndef WIN_SCENE_H
#define WIN_SCENE_H

#include "engine/engine.hpp"

class WinScene {
    public:
        WinScene();

        void clear();
        void start();
    private:
        bool active = false;
};

#endif
