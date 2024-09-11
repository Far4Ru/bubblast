#include "engine/engine.hpp"

MouseManager::MouseManager() {

}

void MouseManager::process() {
    SDL_GetMouseState(&x,&y);
    for (auto const& mouse_hover : mouse_hover_queue) {
        mouse_hover.second(x, y);
    }
    if (clicked) {
        clicked = false;
        for (auto const& mouse_click : mouse_click_queue) {
            mouse_click.second(x, y);
        }
    }
}

void MouseManager::addClick(std::string name, std::function<void(int, int)> func) {
    mouse_click_queue[name] = func;
}

void MouseManager::removeClick(std::string name) {
    mouse_click_queue[name] = [](int x, int y){};
}

bool MouseManager::check(SDL_Rect hit_area, int x, int y) {
    SDL_Rect current_hit_area = {
                engine->game_area->x + hit_area.x * engine->game_area->scale,
                engine->game_area->y + hit_area.y * engine->game_area->scale,
                hit_area.w * engine->game_area->scale,
                hit_area.h * engine->game_area->scale,
            };
    return current_hit_area.x < x &&
                x < (current_hit_area.w + current_hit_area.x) &&
                current_hit_area.y < y &&
                y < (current_hit_area.y + current_hit_area.h);
}

void MouseManager::addHover(std::string name, std::function<void(int, int)> func) {
    mouse_hover_queue[name] = func;
}

void MouseManager::removeHover(std::string name) {
    mouse_hover_queue[name] = [](int x, int y){};
}
