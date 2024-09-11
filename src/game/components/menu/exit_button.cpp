#include "game/game.hpp"

#define EXIT_BUTTON_X 610
#define EXIT_BUTTON_Y 610
#define EXIT_BUTTON_NAME "Выход"
#define EXIT_BUTTON_ID "exit_button"

ExitButton::ExitButton() {
    text = engine->add->text("Airfool");
    text->setText(EXIT_BUTTON_NAME);
    text->x = WIDTH / 2 - text->width / 2;
    text->y = EXIT_BUTTON_Y;

    SDL_Rect hit_area = { EXIT_BUTTON_X, EXIT_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick(EXIT_BUTTON_ID, [&, hit_area](int x, int y) {
        if (engine->mouse->check(hit_area, x, y)) {
            engine->active = false;
        }
    });
    engine->mouse->addHover(EXIT_BUTTON_ID, [&, hit_area](int x, int y) {
        if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> " + (std::string)EXIT_BUTTON_NAME + " <");
            text->x = WIDTH / 2 - text->width / 2 - 15;
        } else {
            text->setText(EXIT_BUTTON_NAME);
            text->x = WIDTH / 2 - text->width / 2;
        }
    });
}

ExitButton::~ExitButton() {
    text->destroy();
    engine->mouse->removeClick(EXIT_BUTTON_ID);
    engine->mouse->removeHover(EXIT_BUTTON_ID);
}
