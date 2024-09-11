#include "game/game.hpp"

#define RESULTS_BUTTON_X 580
#define RESULTS_BUTTON_Y 470
#define RESULTS_BUTTON_ID "results_button"
#define RESULTS_BUTTON_NAME "Результаты"

ResultsButton::ResultsButton() {
    text = engine->add->text("Airfool");
    text->setText(RESULTS_BUTTON_NAME);
    text->x = WIDTH / 2 - text->width / 2;
    text->y = RESULTS_BUTTON_Y;

    SDL_Rect hit_area = { RESULTS_BUTTON_X, RESULTS_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick(RESULTS_BUTTON_ID, [&, hit_area](int x, int y) {
        pressed = engine->mouse->check(hit_area, x, y);
    });
    engine->mouse->addHover(RESULTS_BUTTON_ID, [&, hit_area](int x, int y) {
        if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> " + (std::string)RESULTS_BUTTON_NAME + " <");
            text->x = WIDTH / 2 - text->width / 2 - 14;
        } else {
            text->setText(RESULTS_BUTTON_NAME);
            text->x = WIDTH / 2 - text->width / 2;
        }
    });
}

ResultsButton::~ResultsButton() {
    text->destroy();
    engine->mouse->removeClick(RESULTS_BUTTON_ID);
    engine->mouse->removeHover(RESULTS_BUTTON_ID);
}
