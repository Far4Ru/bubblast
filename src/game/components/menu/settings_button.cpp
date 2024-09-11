#include "game/game.hpp"

#define PLAY_BUTTON_X 580
#define PLAY_BUTTON_Y 540

SettingsButton::SettingsButton() {
    text = engine->add->text("Airfool");
    text->setText("Настройки");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick("settings_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            pressed = true;
        }
    });
    engine->mouse->addHover("settings_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> Настройки <");
            text->x = PLAY_BUTTON_X - 39;
        } else {
            text->setText("Настройки");
            text->x = PLAY_BUTTON_X;
        }
    });
}

SettingsButton::~SettingsButton() {
    text->destroy();
    engine->mouse->removeClick("settings_button");
    engine->mouse->removeHover("settings_button");
}
