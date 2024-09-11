#include "game/components/lose/back_menu_button.hpp"

#define BACK_MENU_BUTTON_X 520
#define BACK_MENU_BUTTON_Y 540
#define BACK_MENU_BUTTON_NAME "Вернуться в меню"
#define BACK_MENU_BUTTON_ID "back_menu_button"

BackMenuButton::BackMenuButton() {
    text = engine->add->text("Airfool");
    text->setText(BACK_MENU_BUTTON_NAME);
    text->x = WIDTH / 2 - text->width / 2;
    text->y = BACK_MENU_BUTTON_Y;

    SDL_Rect hit_area = { BACK_MENU_BUTTON_X, BACK_MENU_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick(BACK_MENU_BUTTON_ID, [&, hit_area](int x, int y) {
        pressed = engine->mouse->check(hit_area, x, y);
    });
    engine->mouse->addHover(BACK_MENU_BUTTON_ID, [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> " + (std::string)BACK_MENU_BUTTON_NAME + " <");
            text->x = WIDTH / 2 - text->width / 2 - 15;
        } else {
            text->setText(BACK_MENU_BUTTON_NAME);
            text->x = WIDTH / 2 - text->width / 2;
        }
    });
}

BackMenuButton::~BackMenuButton() {
    text->destroy();
    engine->mouse->removeClick(BACK_MENU_BUTTON_ID);
    engine->mouse->removeHover(BACK_MENU_BUTTON_ID);
}
