#ifndef SETTINGS_BUTTON_H
#define SETTINGS_BUTTON_H

#include "engine/engine.hpp"

class SettingsButton {
    public:
        SettingsButton();
        ~SettingsButton();

        bool pressed = false;
    private:
        TextObject* text;
};

#endif
