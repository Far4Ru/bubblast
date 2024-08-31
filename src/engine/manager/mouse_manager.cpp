#include "engine/manager/mouse_manager.hpp"

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

void MouseManager::addHover(std::string name, std::function<void(int, int)> func) {
    mouse_hover_queue[name] = func;
}

void MouseManager::removeHover(std::string name) {
    mouse_hover_queue[name] = [](int x, int y){};
}
