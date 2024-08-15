#include <SDL2/SDL.h>
#include <map>
#include <iostream>
#include <functional>

class KeyboardManager {
    public:
        KeyboardManager();
        void process();
        void add(SDL_Scancode code, std::function<void()> func);
    private:
        const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
        std::map<SDL_Scancode, std::function<void()>> key_press_queue = {};
};
