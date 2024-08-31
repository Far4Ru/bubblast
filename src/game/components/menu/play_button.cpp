#include "game/game.hpp"

#define PLAY_BUTTON_X 600
#define PLAY_BUTTON_Y 400

PlayButton::PlayButton() {
    text = engine->add->text("WinterCat");
    text->setText("Play");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 35, 150, 70 };
    engine->mouse->addClick("play_button", [&, hit_area](int x, int y) {
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
            game->menuScene->clear();
            game->gameScene->start();
        }
    });
    engine->mouse->addHover("play_button", [&, hit_area](int x, int y) {
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
            text->setText("> Play <");
            text->x = PLAY_BUTTON_X - 40;
        } else {
            text->setText("Play");
            text->x = PLAY_BUTTON_X;
        }
    });
}

PlayButton::~PlayButton() {
    text->destroy();
    engine->mouse->removeClick("play_button");
    engine->mouse->removeHover("play_button");
}
