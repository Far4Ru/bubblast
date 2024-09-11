#ifndef START_BUTTON_H
#define START_BUTTON_H

#include "engine/engine.hpp"

class StartButton {
    public:
        StartButton();
        ~StartButton();
        
        void setActive(bool value);
        bool pressed = false;
    private:
        TextObject* text;
        bool active = false;
};

#endif
