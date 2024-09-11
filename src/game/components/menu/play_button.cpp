#include "game/game.hpp"

#define PLAY_BUTTON_X 600
#define PLAY_BUTTON_Y 400
#define PLAY_BUTTON_NAME "Играть"
#define PLAY_BUTTON_ID "play_button"

PlayButton::PlayButton() {
    text = engine->add->text("Airfool");
    text->setText(PLAY_BUTTON_NAME);
    text->x = WIDTH / 2 - text->width / 2;
    text->y = PLAY_BUTTON_Y;

    SDL_Rect hit_area = { PLAY_BUTTON_X, PLAY_BUTTON_Y - 15, 150, 70 };
    engine->mouse->addClick(PLAY_BUTTON_ID, [&, hit_area](int x, int y) {
        pressed = engine->mouse->check(hit_area, x, y);
    });
    engine->mouse->addHover(PLAY_BUTTON_ID, [&, hit_area](int x, int y) {
        if (engine->mouse->check(hit_area, x, y)) {
            text->setText("> " + (std::string)PLAY_BUTTON_NAME + " <");
            text->x = WIDTH / 2 - text->width / 2 - 15;
        } else {
            text->setText(PLAY_BUTTON_NAME);
            text->x = WIDTH / 2 - text->width / 2;
        }
    });
}

PlayButton::~PlayButton() {
    text->destroy();
    engine->mouse->removeClick(PLAY_BUTTON_ID);
    engine->mouse->removeHover(PLAY_BUTTON_ID);
}
