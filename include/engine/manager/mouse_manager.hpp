#include <SDL2/SDL.h>
#include <map>
#include <iostream>
#include <functional>

class MouseManager {
    public:
        MouseManager();
        void process();
        int x = 0, y = 0;
        void add(std::string name, std::function<void(int, int)> func);
        void remove(std::string name);
        bool clicked = false;
    private:
        std::map<std::string, std::function<void(int, int)>> mouse_click_queue = {};
};
