#include "game/game.hpp"

#define SETTINGS_BUTTON_X 580
#define SETTINGS_BUTTON_Y 540
#define SETTINGS_BUTTON_ID "settings_button"
#define SETTINGS_BUTTON_NAME "Настройки"

SettingsButton::SettingsButton() {
    text = engine->add->text("Airfool");
    text->setText(SETTINGS_BUTTON_NAME);
    text->x = WIDTH / 2 - text->width / 2;
    text->y = SETTINGS_BUTTON_Y;

    SDL_Rect hit_area = { SETTINGS_BUTTON_X, SETTINGS_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick(SETTINGS_BUTTON_ID, [&, hit_area](int x, int y) {
        pressed = engine->mouse->check(hit_area, x, y);
    });
    engine->mouse->addHover(SETTINGS_BUTTON_ID, [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> " + (std::string)SETTINGS_BUTTON_NAME + " <");
            text->x = WIDTH / 2 - text->width / 2 - 15;
        } else {
            text->setText(SETTINGS_BUTTON_NAME);
            text->x = WIDTH / 2 - text->width / 2;
        }
    });
}

SettingsButton::~SettingsButton() {
    text->destroy();
    engine->mouse->removeClick(SETTINGS_BUTTON_ID);
    engine->mouse->removeHover(SETTINGS_BUTTON_ID);
}
