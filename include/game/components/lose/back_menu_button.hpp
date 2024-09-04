#ifndef BACK_MENU_BUTTON_H
#define BACK_MENU_BUTTON_H

#include "engine/engine.hpp"

class BackMenuButton {
    public:
        BackMenuButton();
        ~BackMenuButton();
        
        bool pressed = false;
    private:
        TextObject* text;
};

#endif
