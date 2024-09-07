#ifndef RESULTS_SCENE_H
#define RESULTS_SCENE_H

#include "engine/engine.hpp"
#include "game/scenes/scene_base.hpp"
#include "game/components/results/results_title_text.hpp"
#include "game/components/results/results_table.hpp"

class ResultsScene : public SceneBase {
    public:
        ResultsScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
        BackMenuButton* back_to_menu;
        ResultsTitleText* title;
        ResultsTable* table;
};

#endif
