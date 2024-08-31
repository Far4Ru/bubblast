#include "engine/engine.hpp"
#include "game/components/menu_background.hpp"

class MenuScene {
    public:
        MenuScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
};
