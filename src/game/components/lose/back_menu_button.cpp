#include "game/components/lose/back_menu_button.hpp"

#define PLAY_BUTTON_X 520
#define PLAY_BUTTON_Y 540

BackMenuButton::BackMenuButton() {
    text = engine->add->text("Airfool");
    text->setText("Вернуться в меню");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick("back_menu_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            pressed = true;
        }
    });
    engine->mouse->addHover("back_menu_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> Вернуться в меню <");
            text->x = PLAY_BUTTON_X - 40;
        } else {
            text->setText("Вернуться в меню");
            text->x = PLAY_BUTTON_X;
        }
    });
}

BackMenuButton::~BackMenuButton() {
    text->destroy();
    engine->mouse->removeClick("back_menu_button");
    engine->mouse->removeHover("back_menu_button");
}
