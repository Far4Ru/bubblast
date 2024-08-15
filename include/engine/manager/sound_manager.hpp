#include <iostream>
#include <SDL2/SDL_mixer.h>

#include "engine/loader/loader.hpp"

class SoundManager {
    public:
        SoundManager(Loader* loader);
        void playSound(std::string name);
        void playMusic(std::string name);
        void resumeMusic();
        void pauseMusic();
    private:
        Loader* loader;
};
