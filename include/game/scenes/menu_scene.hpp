#include "engine/engine.hpp"
#include "game/components/menu_background.hpp"
#include "game/components/logo.hpp"
#include "game/components/play_button.hpp"

class MenuScene {
    public:
        MenuScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
        Logo* logo;
        PlayButton* play;
};
