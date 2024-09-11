#include "game/components/settings/fullscreen_settings.hpp"

#define FULLSCREEN_SETTINGS_Y 250

FullscreenSettings::FullscreenSettings() {
    title = engine->add->text("Airfool");
    title->setText("Полноэкранный режим:");
    title->x = 100;
    title->y = FULLSCREEN_SETTINGS_Y;

    left = engine->add->text("Airfool");
    left->setText(engine->isFullscreen() ? "<" : "");
    left->x = 750;
    left->y = FULLSCREEN_SETTINGS_Y;
    
    value = engine->add->text("Airfool");
    value->setText(engine->isFullscreen() ? "ВКЛ" : "ВЫКЛ");
    value->x = 800;
    value->y = FULLSCREEN_SETTINGS_Y;
    
    right = engine->add->text("Airfool");
    right->setText(engine->isFullscreen() ? "" : ">");
    right->x = 950;
    right->y = FULLSCREEN_SETTINGS_Y;

    SDL_Rect left_hit_area = { left->x, left->y - 15, 150, 70 };
    engine->mouse->addClick("left_fullscreen_button", [&, left_hit_area](int x, int y) {
        if (engine->mouse->check(left_hit_area, x, y)) {
            left->setText("");
            right->setText(">");
            engine->setFullscreen(false);
            value->setText("ВЫКЛ");
        }
    });

    SDL_Rect right_hit_area = { right->x, right->y - 15, 150, 70 };
    engine->mouse->addClick("right_fullscreen_button", [&, right_hit_area](int x, int y) {
        if (engine->mouse->check(right_hit_area, x, y)) {
            left->setText("<");
            right->setText("");
            engine->setFullscreen(true);
            value->setText("ВКЛ");
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