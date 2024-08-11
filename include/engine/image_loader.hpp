#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <iostream>
#include <dirent.h>
#include <vector>

#define ASSETS_FOLDER "assets"
#define ASSETS_FOLDER_PATH "assets/"
#define IMAGE_EXTENSION ".png"

class ImageLoader {
    public:
        ImageLoader();
        ~ImageLoader();
        void load();
    private:
        void getImageNames();
        std::vector<std::string> imageNames;
        std::map<std::string, SDL_Surface*> images = {};
};
