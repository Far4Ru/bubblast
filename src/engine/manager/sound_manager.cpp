#include "engine/manager/sound_manager.hpp"

SoundManager::SoundManager(Loader* loader) {
    this->loader = loader;
}

void SoundManager::playSound(std::string name) {
    Mix_PlayChannel(-1, loader->getChunk(name), 0);
}

void SoundManager::playMusic(std::string name, bool loop) {
    if (current_music_name == name && loop) { return; }
    Mix_PlayMusic(loader->getMusic(name), loop ? -1 : 0);
    if (loop) { current_music_name = name; }
}

void SoundManager::resumeMusic() {
    Mix_ResumeMusic();
}

void SoundManager::pauseMusic() {
    Mix_PauseMusic();
    current_music_name = "";
}
