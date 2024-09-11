#include "game/game.hpp"

#define PLAY_BUTTON_X 610
#define PLAY_BUTTON_Y 610

ExitButton::ExitButton() {
    text = engine->add->text("Airfool");
    text->setText("Выход");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick("exit_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            engine->active = false;
        }
    });
    engine->mouse->addHover("exit_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> Выход <");
            text->x = PLAY_BUTTON_X - 39;
        } else {
            text->setText("Выход");
            text->x = PLAY_BUTTON_X;
        }
    });
}

ExitButton::~ExitButton() {
    text->destroy();
    engine->mouse->removeClick("exit_button");
    engine->mouse->removeHover("exit_button");
}
