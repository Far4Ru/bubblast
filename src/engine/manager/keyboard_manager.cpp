#include "engine/manager/keyboard_manager.hpp"

KeyboardManager::KeyboardManager() {
    //
}

void KeyboardManager::process() {
    for (auto const& key_press : key_press_queue) {
        if (keyboard_state_array[key_press.first]) {
            key_press.second();
        }
    }
}

std::string KeyboardManager::getKey() {
    for (int i = 4; i < 30; i++) {
        if (keyboard_state_array[(SDL_Scancode)i]) {
            return SDL_GetScancodeName((SDL_Scancode)i);
        }
    }
    return "";
}

void KeyboardManager::add(SDL_Scancode code, std::function<void()> func) {
    key_press_queue[code] = func;
}

void KeyboardManager::remove(SDL_Scancode code) {
    key_press_queue[code] = [](){};
}
