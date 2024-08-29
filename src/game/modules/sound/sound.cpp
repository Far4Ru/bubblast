#include "game/modules/sound/sound.hpp"

Sound::Sound() {
    engine->sound->playMusic("PositiveEnergy");
    engine->keyboard->add(SDL_SCANCODE_1, [&]() {
        engine->sound->pauseMusic();
    });
    engine->keyboard->add(SDL_SCANCODE_2, [&]() {
        engine->sound->resumeMusic();
    });
}

void Sound::playFire() {
    engine->sound->playSound("BubbleSpell");
}
