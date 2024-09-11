#include "game/components/lose/restart_button.hpp"

#define RESTART_BUTTON_X 580
#define RESTART_BUTTON_Y 470
#define RESTART_BUTTON_NAME "Заново"
#define RESTART_BUTTON_ID "restart_button"

RestartButton::RestartButton() {
    text = engine->add->text("Airfool");
    text->setText(RESTART_BUTTON_NAME);
    text->x = WIDTH / 2 - text->width / 2;
    text->y = RESTART_BUTTON_Y;

    SDL_Rect hit_area = { RESTART_BUTTON_X, RESTART_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick(RESTART_BUTTON_ID, [&, hit_area](int x, int y) {
        pressed = engine->mouse->check(hit_area, x, y);
    });
    engine->mouse->addHover(RESTART_BUTTON_ID, [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> " + (std::string)RESTART_BUTTON_NAME + " <");
            text->x = WIDTH / 2 - text->width / 2 - 15.5;
        } else {
            text->setText(RESTART_BUTTON_NAME);
            text->x = WIDTH / 2 - text->width / 2;
        }
    });
}

RestartButton::~RestartButton() {
    text->destroy();
    engine->mouse->removeClick(RESTART_BUTTON_ID);
    engine->mouse->removeHover(RESTART_BUTTON_ID);
}
