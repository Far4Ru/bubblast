#include "game/components/settings/sound_settings.hpp"

#define SOUND_SETTINGS_Y 410

SoundSettings::SoundSettings() {
    title = engine->add->text("Airfool");
    title->setText("Громкость звуков:");
    title->x = 240;
    title->y = SOUND_SETTINGS_Y;

    left = engine->add->text("Airfool");
    left->setText("-");
    left->x = 760;
    left->y = SOUND_SETTINGS_Y;

    int mix_value = Mix_VolumeChunk(engine->loader->getChunk("BubbleSpell"), -1);
    value = mix_value > 100 ? mix_value * 0.78125 : mix_value;

    value_text = engine->add->text("Airfool");
    value_text->setText(std::to_string(value) + "%");
    value_text->x = 810;
    value_text->y = SOUND_SETTINGS_Y;
    
    right = engine->add->text("Airfool");
    right->setText("+");
    right->x = 935;
    right->y = SOUND_SETTINGS_Y;

    if (value <= 0) {
        left->setText("");
    } else if (value >= 100) {
        right->setText("");
    }

    SDL_Rect left_hit_area = { left->x, left->y - 15, 150, 70 };
    engine->mouse->addClick("left_sound_button", [&, left_hit_area](int x, int y) {
        if (engine->mouse->check(left_hit_area, x, y)) {
            if (value <= 0) {
                return;
            }
            right->setText("+");
            value -= 10;
            if (value <= 0) {
                left->setText("");
            }
            value_text->setText(std::to_string(value) + "%");
            Mix_VolumeChunk(engine->loader->getChunk("BubbleSpell"), (128 / 100) * value);
            engine->sound->playSound("BubbleSpell");
        }
    });

    SDL_Rect right_hit_area = { right->x, right->y - 15, 150, 70 };
    engine->mouse->addClick("right_sound_button", [&, right_hit_area](int x, int y) {
        if (engine->mouse->check(right_hit_area, x, y)) {
            if (value >= 100) {
                return;
            }
            left->setText("-");
            value += 10;
            if (value >= 100) {
                right->setText("");
            }
            value_text->setText(std::to_string(value) + "%");
            Mix_VolumeChunk(engine->loader->getChunk("BubbleSpell"), (128 / 100) * value);
            engine->sound->playSound("BubbleSpell");
        }
    });
}

SoundSettings::~SoundSettings() {
    title->destroy();
    left->destroy();
    value_text->destroy();
    right->destroy();
    engine->mouse->removeClick("left_sound_button");
    engine->mouse->removeClick("right_sound_button");
}
