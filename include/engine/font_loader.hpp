#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <map>
#include <iostream>
#include <dirent.h>
#include <vector>

class FontLoader {
    public:
        FontLoader();
        ~FontLoader();

        TTF_Font* get(std::string font);
    private:
        void load();
        void getFontNames();
        std::vector<std::string> fontNames;
        std::map<std::string, TTF_Font*> fonts = {};
};
