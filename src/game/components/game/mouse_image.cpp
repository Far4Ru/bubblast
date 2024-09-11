#include "game/components/game/mouse_image.hpp"

MouseImage::MouseImage() {
    image = engine->add->image("cursor");
    SDL_Rect crop = { 366, 346, 228, 212 };
    image->scale = 0.2;
    image->crop = crop;
    image->width = crop.w;
    image->height = crop.h;
    auto imageFunc = [&]() {
        image->x = -(image->width * image->scale) / 2 + (engine->mouse->x - engine->game_area->x) / engine->game_area->scale;
        image->y = -(image->height * image->scale) / 2 + (engine->mouse->y - engine->game_area->y ) / engine->game_area->scale;
    };
    image->setProcess(imageFunc);
    SDL_ShowCursor(false);
}

MouseImage::~MouseImage() {
    image->destroy();
    SDL_ShowCursor(true);

}
