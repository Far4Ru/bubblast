#include <SDL2/SDL.h>
#include <map>
#include <iostream>
#include <dirent.h>
#include <vector>
#include <SDL2/SDL_mixer.h>

class SoundLoader {
    public:
        SoundLoader();
        ~SoundLoader();

        Mix_Music* getMusic(std::string music);
        Mix_Chunk* getChunk(std::string chunk);
    private:
        void load();
        void getSoundNames();
        std::vector<std::string> chunkNames;
        std::vector<std::string> musicNames;
        std::map<std::string, Mix_Chunk*> chunks = {};
        std::map<std::string, Mix_Music*> musics = {};
};
