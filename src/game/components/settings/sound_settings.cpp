#include "game/components/settings/sound_settings.hpp"

#define SOUND_SETTINGS_Y 410

SoundSettings::SoundSettings() {
    title = engine->add->text("WinterCat");
    title->setText("Sound volume:");
    title->x = 350;
    title->y = SOUND_SETTINGS_Y;

    left = engine->add->text("WinterCat");
    left->setText("-");
    left->x = 700;
    left->y = SOUND_SETTINGS_Y;

    int mix_value = Mix_VolumeChunk(engine->loader->getChunk("BubbleSpell"), -1);
    value = mix_value > 100 ? mix_value * 0.78125 : mix_value;

    value_text = engine->add->text("WinterCat");
    value_text->setText(std::to_string(value) + "%");
    value_text->x = 750;
    value_text->y = SOUND_SETTINGS_Y;
    
    right = engine->add->text("WinterCat");
    right->setText("+");
    right->x = 875;
    right->y = SOUND_SETTINGS_Y;

    SDL_Rect left_hit_area = { left->x, left->y - 15, 150, 70 };
    engine->mouse->addClick("left_sound_button", [&, left_hit_area](int x, int y) {
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
