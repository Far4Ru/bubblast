#include "game/game.hpp"

#define PLAY_BUTTON_X 600
#define PLAY_BUTTON_Y 400

PlayButton::PlayButton() {
    text = engine->add->text("Airfool");
    text->setText("Играть");
    text->x = PLAY_BUTTON_X;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick("play_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            pressed = true;
        }
    });
    engine->mouse->addHover("play_button", [&, hit_area](int x, int y) {
            if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> Играть <");
            text->x = PLAY_BUTTON_X - 40;
        } else {
            text->setText("Играть");
            text->x = PLAY_BUTTON_X;
        }
    });
}

PlayButton::~PlayButton() {
    text->destroy();
    engine->mouse->removeClick("play_button");
    engine->mouse->removeHover("play_button");
}
