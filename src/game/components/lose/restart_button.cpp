#include "game/components/lose/restart_button.hpp"

#define PLAY_BUTTON_X 580
#define PLAY_BUTTON_Y 470

RestartButton::RestartButton() {
    text = engine->add->text("Airfool");
    text->setText("Заново");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick("restart_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            pressed = true;
        }
    });
    engine->mouse->addHover("restart_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> Заново <");
            text->x = PLAY_BUTTON_X - 40;
        } else {
            text->setText("Заново");
            text->x = PLAY_BUTTON_X;
        }
    });
}

RestartButton::~RestartButton() {
    text->destroy();
    engine->mouse->removeClick("restart_button");
    engine->mouse->removeHover("restart_button");
}
