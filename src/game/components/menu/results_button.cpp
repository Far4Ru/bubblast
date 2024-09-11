#include "game/game.hpp"

#define PLAY_BUTTON_X 580
#define PLAY_BUTTON_Y 470

ResultsButton::ResultsButton() {
    text = engine->add->text("Airfool");
    text->setText("Результаты");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick("results_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            pressed = true;
        }
    });
    engine->mouse->addHover("results_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> Результаты <");
            text->x = PLAY_BUTTON_X - 40;
        } else {
            text->setText("Результаты");
            text->x = PLAY_BUTTON_X;
        }
    });
}

ResultsButton::~ResultsButton() {
    text->destroy();
    engine->mouse->removeClick("results_button");
    engine->mouse->removeHover("results_button");
}
