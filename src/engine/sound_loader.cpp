#include "engine/sound_loader.hpp"

SoundLoader::SoundLoader() {
    getSoundNames();
    load();
}

SoundLoader::~SoundLoader() {
}

void SoundLoader::getSoundNames() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("assets/sounds/chunk")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            std::string filename = ent->d_name;
            if (filename.find(".wav") != std::string::npos) {
                chunkNames.push_back(filename);
            }
        }
        closedir (dir);
    } else {
        SDL_Log("Could not open chunks");
    }
    if ((dir = opendir ("assets/sounds/music")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            std::string filename = ent->d_name;
            if (filename.find(".wav") != std::string::npos) {
                musicNames.push_back(filename);
            }
        }
        closedir (dir);
    } else {
        SDL_Log("Could not open music");
    }
}

Mix_Music* SoundLoader::getMusic(std::string music) {
    return musics[music];
}

Mix_Chunk* SoundLoader::getChunk(std::string chunk) {
    return chunks[chunk];
}

void SoundLoader::load() {
    for (const std::string& chunkName : chunkNames) {
        Mix_Chunk* chunk = Mix_LoadWAV(("assets/sounds/chunk/" + chunkName).c_str());
        std::string name = chunkName.substr(0, chunkName.find(".wav"));
        chunks[name] = chunk;
        if (chunk == NULL) {
            SDL_Log("%s", ("Can't load chunk: " + chunkName).c_str());
        }
    }
    for (const std::string& musicName : musicNames) {
        Mix_Music* music = Mix_LoadMUS(("assets/sounds/music/" + musicName).c_str());
        std::string name = musicName.substr(0, musicName.find(".wav"));
        musics[name] = music;
        if (music == NULL) {
            SDL_Log("%s", ("Can't load music: " + musicName).c_str());
        }
    }
}
