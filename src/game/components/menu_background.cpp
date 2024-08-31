#include "game/game.hpp"

MenuBackground::MenuBackground() {
    image = engine->add->image("bg_back");
    image->scale = (float)2/3;

    SDL_Rect hit_area = { 0, 0, WIDTH, HEIGHT };
    engine->mouse->add("menu_background", [&, hit_area](int x, int y) {
        SDL_Rect current_hit_area = {
            engine->game_area->x + hit_area.x,
            engine->game_area->y + hit_area.y,
            hit_area.w * engine->game_area->scale,
            hit_area.h * engine->game_area->scale,
        };
        if (current_hit_area.x < x &&
            x < (current_hit_area.w + current_hit_area.x) &&
            current_hit_area.y < y &&
            y < (current_hit_area.y + current_hit_area.h)
            ) {
            game->menuScene->clear();
            game->gameScene->start();
        }
    });
}

MenuBackground::~MenuBackground() {
    image->destroy();
    engine->mouse->remove("menu_background");
}
