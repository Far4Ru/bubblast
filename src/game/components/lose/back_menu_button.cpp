#include "game/components/lose/back_menu_button.hpp"

#define PLAY_BUTTON_X 520
#define PLAY_BUTTON_Y 540

BackMenuButton::BackMenuButton() {
    text = engine->add->text("WinterCat");
    text->setText("Back to menu");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick("back_menu_button", [&, hit_area](int x, int y) {
        SDL_Rect current_hit_area = {
            engine->game_area->x + hit_area.x,
            engine->game_area->y + hit_area.y,
            hit_area.w * engine->game_area->scale,
            hit_area.h * engine->game_area->scale,
        };
        if (current_hit_area.x < x &&
            x < (current_hit_area.w + current_hit_area.x) &&
            current_hit_area.y < y &&
            y < (current_hit_area.y + current_hit_area.h)
            ) {
            pressed = true;
        }
    });
    engine->mouse->addHover("back_menu_button", [&, hit_area](int x, int y) {
        SDL_Rect current_hit_area = {
            engine->game_area->x + hit_area.x,
            engine->game_area->y + hit_area.y,
            hit_area.w * engine->game_area->scale,
            hit_area.h * engine->game_area->scale,
        };
        if (current_hit_area.x < x &&
            x < (current_hit_area.w + current_hit_area.x) &&
            current_hit_area.y < y &&
            y < (current_hit_area.y + current_hit_area.h)
            ) {
            text->setText("> Back to menu <");
            text->x = PLAY_BUTTON_X - 40;
        } else {
            text->setText("Back to menu");
            text->x = PLAY_BUTTON_X;
        }
    });
}

BackMenuButton::~BackMenuButton() {
    text->destroy();
    engine->mouse->removeClick("back_menu_button");
    engine->mouse->removeHover("back_menu_button");
}
