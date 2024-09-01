#ifndef RESULTS_SCENE_H
#define RESULTS_SCENE_H

#include "engine/engine.hpp"

class ResultsScene {
    public:
        ResultsScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
};

#endif
