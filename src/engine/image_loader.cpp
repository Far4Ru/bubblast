#include "engine/image_loader.hpp"

ImageLoader::ImageLoader() {
    getImageNames();
    load();
}

ImageLoader::~ImageLoader() {
    for (auto const& image : images) {
        SDL_FreeSurface(image.second);
    }
}

void ImageLoader::getImageNames() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (ASSETS_FOLDER)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            std::string filename = ent->d_name;
            if (filename.find(IMAGE_EXTENSION) != std::string::npos) {
                imageNames.push_back(filename);
            }
        }
        closedir (dir);
    } else {
        SDL_Log("Could not open assets");
    }
}

SDL_Surface* ImageLoader::get(std::string image) {
    return images[image];
}

void ImageLoader::load() {
    for (const std::string& imageName : imageNames) {
        SDL_Surface* imageSurface = IMG_Load((ASSETS_FOLDER_PATH + imageName).c_str());
        std::string name = imageName.substr(0, imageName.find(IMAGE_EXTENSION));
        images[name] = imageSurface;
        if (imageSurface == NULL) {
            SDL_Log("%s", ("Can't load image: " + imageName).c_str());
        }
    }
}
