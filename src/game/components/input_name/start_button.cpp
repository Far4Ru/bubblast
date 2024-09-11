#include "game/components/input_name/start_button.hpp"

#define PLAY_BUTTON_X 600
#define PLAY_BUTTON_Y 300

StartButton::StartButton() {
    text = engine->add->text("Airfool");
    text->setText("Начать");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick("start_button", [&, hit_area](int x, int y) {
        if (active) {
            if (engine->mouse->check(hit_area, x, y)) {
                pressed = true;
            }
        }
    });
    engine->mouse->addHover("start_button", [&, hit_area](int x, int y) {
        if (active) {
            if (engine->mouse->check(hit_area, x, y)) {
                text->setText("> Начать <");
                text->x = PLAY_BUTTON_X - 39;
            } else {
                text->setText("Начать");
                text->x = PLAY_BUTTON_X;
            }
        }
    });
}

void StartButton::setActive(bool value) {
    active = value;
    text->active = active;
}

StartButton::~StartButton() {
    text->destroy();
    engine->mouse->removeClick("start_button");
    engine->mouse->removeHover("start_button");
}
