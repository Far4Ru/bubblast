#ifndef RESULTS_SCENE_H
#define RESULTS_SCENE_H

#include "engine/engine.hpp"
#include "game/scenes/scene_base.hpp"

class ResultsScene : public SceneBase {
    public:
        ResultsScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
};

#endif
