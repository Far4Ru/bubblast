#include "engine/manager/mouse_manager.hpp"

MouseManager::MouseManager() {

}

void MouseManager::process() {
    SDL_GetMouseState(&x,&y);
    if (clicked) {
        clicked = false;
        for (auto const& mouse_click : mouse_click_queue) {
            mouse_click.second(x, y);
        }
    }
}

void MouseManager::add(std::string name, std::function<void(int, int)> func) {
    mouse_click_queue[name] = func;
}

void MouseManager::remove(std::string name) {
    mouse_click_queue[name] = [](int x, int y){};
}
