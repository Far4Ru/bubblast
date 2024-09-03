#include "game/modules/sound/sound.hpp"

Sound::Sound() {
    engine->sound->playMusic("game_music");
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

Sound::~Sound() {
    engine->sound->pauseMusic();
    engine->keyboard->remove(SDL_SCANCODE_1);
    engine->keyboard->remove(SDL_SCANCODE_2);
}
