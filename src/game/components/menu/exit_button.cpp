#include "game/game.hpp"

#define PLAY_BUTTON_X 610
#define PLAY_BUTTON_Y 610

ExitButton::ExitButton() {
    text = engine->add->text("WinterCat");
    text->setText("Exit");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 35, 150, 70 };
    engine->mouse->addClick("exit_button", [&, hit_area](int x, int y) {
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
            engine->active = false;
        }
    });
    engine->mouse->addHover("exit_button", [&, hit_area](int x, int y) {
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
            text->setText("> Exit <");
            text->x = PLAY_BUTTON_X - 39;
        } else {
            text->setText("Exit");
            text->x = PLAY_BUTTON_X;
        }
    });
}

ExitButton::~ExitButton() {
    text->destroy();
    engine->mouse->removeClick("exit_button");
    engine->mouse->removeHover("exit_button");
}
