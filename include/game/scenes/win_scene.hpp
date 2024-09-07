#ifndef WIN_SCENE_H
#define WIN_SCENE_H

#include <fstream>

#include "engine/engine.hpp"
#include "game/scenes/scene_base.hpp"
#include "game/components/win/win_title.hpp"
#include "game/components/lose/restart_button.hpp"
#include "game/components/lose/back_menu_button.hpp"

class WinScene : public SceneBase {
    public:
        WinScene();

        void clear();
        void start();

        void save_result();
    private:
        bool active = false;
        MenuBackground* background;
        WinTitle* title;
        RestartButton* restart;
        BackMenuButton* back_to_menu;
};

#endif
