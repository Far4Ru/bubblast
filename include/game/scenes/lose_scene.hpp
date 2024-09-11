#ifndef LOSE_SCENE_H
#define LOSE_SCENE_H

#include "engine/engine.hpp"
#include "game/scenes/scene_base.hpp"
#include "game/components/lose/restart_button.hpp"
#include "game/components/lose/lose_title.hpp"
#include "game/components/lose/back_menu_button.hpp"
#include "game/components/lose/score_text.hpp"

class LoseScene : public SceneBase {
    public:
        LoseScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
        LoseTitle* title;
        ScoreText* score;
        RestartButton* restart;
        BackMenuButton* back_to_menu;

};

#endif
