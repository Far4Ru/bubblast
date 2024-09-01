#ifndef LOSE_SCENE_H
#define LOSE_SCENE_H

#include "engine/engine.hpp"

class LoseScene {
    public:
        LoseScene();

        void clear();
        void start();
    private:
        bool active = false;
};

#endif
