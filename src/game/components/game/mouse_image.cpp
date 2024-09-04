#include "game/components/game/mouse_image.hpp"

MouseImage::MouseImage() {
    image = engine->add->image("cursor");
    SDL_Rect crop = { 366, 346, 228, 212 };
    image->scale = 0.25;
    image->crop = crop;
    image->width = crop.w;
    image->height = crop.h;
    auto imageFunc = [&]() {
        image->x = engine->mouse->x - (image->width * image->scale) / 2;
        image->y = engine->mouse->y - (image->height * image->scale) / 2;
    };
    image->setProcess(imageFunc);
    SDL_ShowCursor(false);
}

MouseImage::~MouseImage() {
    image->destroy();
    SDL_ShowCursor(true);

}
