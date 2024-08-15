#include "engine/manager/keyboard_manager.hpp"

KeyboardManager::KeyboardManager() {

}

void KeyboardManager::process() {
    for (auto const& key_press : key_press_queue) {
        if (keyboard_state_array[key_press.first]) {
            key_press.second();
        }
    }
}

void KeyboardManager::add(SDL_Scancode code, std::function<void()> func) {
    key_press_queue[code] = func;
}
