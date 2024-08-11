#include "engine/loader/image_loader.hpp"
#include "engine/loader/font_loader.hpp"
#include "engine/loader/sound_loader.hpp"

class Loader {
    public:
        Loader();
        ~Loader();

        TTF_Font* getFont(std::string font);
        SDL_Surface* getImage(std::string image);
        Mix_Music* getMusic(std::string music);
        Mix_Chunk* getChunk(std::string chunk);
    private:
        ImageLoader* imageLoader;
        SoundLoader* soundLoader;
        FontLoader* fontLoader;
};
