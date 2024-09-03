#include "game/game.hpp"

#define PLAY_BUTTON_X 580
#define PLAY_BUTTON_Y 470

ResultsButton::ResultsButton() {
    text = engine->add->text("WinterCat");
    text->setText("Results");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick("results_button", [&, hit_area](int x, int y) {
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
    engine->mouse->addHover("results_button", [&, hit_area](int x, int y) {
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
            text->setText("> Results <");
            text->x = PLAY_BUTTON_X - 40;
        } else {
            text->setText("Results");
            text->x = PLAY_BUTTON_X;
        }
    });
}

ResultsButton::~ResultsButton() {
    text->destroy();
    engine->mouse->removeClick("results_button");
    engine->mouse->removeHover("results_button");
}
