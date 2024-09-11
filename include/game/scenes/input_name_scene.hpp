#ifndef INPUT_NAME_SCENE_H
#define INPUT_NAME_SCENE_H

#include "engine/engine.hpp"
#include "game/components/menu/menu_background.hpp"
#include "game/components/input_name/input_name_field.hpp"
#include "game/components/lose/back_menu_button.hpp"
#include "game/components/input_name/start_button.hpp"
#include "game/components/input_name/input_name_title.hpp"
#include "game/scenes/scene_base.hpp"

class InputNameScene : public SceneBase {
    public:
        InputNameScene();

        void clear();
        void start();

        MenuBackground* background;
        InputNameField* inputNameField;
        InputNameTitle* title;
        StartButton* start_button;
        BackMenuButton* back_to_menu;
    private:
        bool active = false;
};

#endif
