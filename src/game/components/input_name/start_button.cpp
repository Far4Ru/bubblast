#include "game/components/input_name/start_button.hpp"

#define START_BUTTON_X 600
#define START_BUTTON_Y 300
#define START_BUTTON_NAME "Начать"
#define START_BUTTON_ID "start_button"

StartButton::StartButton() {
    text = engine->add->text("Airfool");
    text->setText(START_BUTTON_NAME);
    text->x = WIDTH / 2 - text->width / 2;
    text->y = START_BUTTON_Y;

    SDL_Rect hit_area = { START_BUTTON_X, START_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick(START_BUTTON_ID, [&, hit_area](int x, int y) {
        if (active) {
            if (engine->mouse->check(hit_area, x, y)) {
                pressed = true;
            }
        }
    });
    engine->mouse->addHover(START_BUTTON_ID, [&, hit_area](int x, int y) {
        if (active) {
            if (engine->mouse->check(hit_area, x, y)) {
                text->setText("> " + (std::string)START_BUTTON_NAME + " <");
                text->x = WIDTH / 2 - text->width / 2 - 16;
            } else {
                text->setText(START_BUTTON_NAME);
                text->x = WIDTH / 2 - text->width / 2;
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
    engine->mouse->removeClick(START_BUTTON_ID);
    engine->mouse->removeHover(START_BUTTON_ID);
}
