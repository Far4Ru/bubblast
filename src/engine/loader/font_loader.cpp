#include "engine/loader/font_loader.hpp"

FontLoader::FontLoader() {
    getFontNames();
    load();
}

FontLoader::~FontLoader() {
}

void FontLoader::getFontNames() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("assets/fonts")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            std::string filename = ent->d_name;
            if (filename.find(".ttf") != std::string::npos) {
                fontNames.push_back(filename);
            }
        }
        closedir (dir);
    } else {
        SDL_Log("Could not open assets");
    }
}

TTF_Font* FontLoader::get(std::string font) {
    return fonts[font];
}

void FontLoader::load() {
    for (const std::string& fontName : fontNames) {
        TTF_Font* font = TTF_OpenFont(("assets/fonts/" + fontName).c_str(), 52);
        std::string name = fontName.substr(0, fontName.find(".ttf"));
        fonts[name] = font;
        if (font == NULL) {
            SDL_Log("%s", ("Can't load font: " + fontName).c_str());
        }
    }
}
