#include "game/components/settings/fullscreen_settings.hpp"

#define FULLSCREEN_SETTINGS_Y 250

FullscreenSettings::FullscreenSettings() {
    title = engine->add->text("WinterCat");
    title->setText("Fullscreen:");
    title->x = 450;
    title->y = FULLSCREEN_SETTINGS_Y;

    left = engine->add->text("WinterCat");
    left->setText(engine->isFullscreen() ? "<" : "");
    left->x = 700;
    left->y = FULLSCREEN_SETTINGS_Y;
    
    value = engine->add->text("WinterCat");
    value->setText(engine->isFullscreen() ? "ON" : "OFF");
    value->x = 750;
    value->y = FULLSCREEN_SETTINGS_Y;
    
    right = engine->add->text("WinterCat");
    right->setText(engine->isFullscreen() ? "" : ">");
    right->x = 875;
    right->y = FULLSCREEN_SETTINGS_Y;

    SDL_Rect left_hit_area = { left->x, left->y - 15, 150, 70 };
    engine->mouse->addClick("left_fullscreen_button", [&, left_hit_area](int x, int y) {
        SDL_Rect current_hit_area = {
            engine->game_area->x + left_hit_area.x,
            engine->game_area->y + left_hit_area.y,
            left_hit_area.w * engine->game_area->scale,
            left_hit_area.h * engine->game_area->scale,
        };
        if (current_hit_area.x < x &&
            x < (current_hit_area.w + current_hit_area.x) &&
            current_hit_area.y < y &&
            y < (current_hit_area.y + current_hit_area.h)
            ) {
            left->setText("");
            right->setText(">");
            engine->setFullscreen(false);
            value->setText("OFF");
        }
    });

    SDL_Rect right_hit_area = { right->x, right->y - 15, 150, 70 };
    engine->mouse->addClick("right_fullscreen_button", [&, right_hit_area](int x, int y) {
        SDL_Rect current_hit_area = {
            engine->game_area->x + right_hit_area.x,
            engine->game_area->y + right_hit_area.y,
            right_hit_area.w * engine->game_area->scale,
            right_hit_area.h * engine->game_area->scale,
        };
        if (current_hit_area.x < x &&
            x < (current_hit_area.w + current_hit_area.x) &&
            current_hit_area.y < y &&
            y < (current_hit_area.y + current_hit_area.h)
            ) {
            left->setText("<");
            right->setText("");
            engine->setFullscreen(true);
            value->setText("ON");
        }
    });
}

FullscreenSettings::~FullscreenSettings() {
    title->destroy();
    left->destroy();
    value->destroy();
    right->destroy();
    engine->mouse->removeClick("left_fullscreen_button");
    engine->mouse->removeClick("right_fullscreen_button");
}