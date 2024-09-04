#ifndef RESTART_BUTTON_H
#define RESTART_BUTTON_H

#include "engine/engine.hpp"

class RestartButton {
    public:
        RestartButton();
        ~RestartButton();
        
        bool pressed = false;
    private:
        TextObject* text;
};

#endif
