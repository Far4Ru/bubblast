#include "engine/sound_manager.hpp"

SoundManager::SoundManager(Loader* loader) {
    this->loader = loader;
}

void SoundManager::playSound(std::string name) {
    Mix_PlayChannel(-1, loader->getChunk(name), 0);
}

void SoundManager::playMusic(std::string name) {
    Mix_PlayMusic(loader->getMusic(name), -1);
}

void SoundManager::resumeMusic() {
    Mix_ResumeMusic();
}

void SoundManager::pauseMusic() {
    Mix_PauseMusic();
}
