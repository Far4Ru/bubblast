#include <SDL2/SDL.h>
#include <map>
#include <iostream>
#include <functional>

class MouseManager {
    public:
        MouseManager();
        void process();
        int x = 0, y = 0;
        void addClick(std::string name, std::function<void(int, int)> func);
        void removeClick(std::string name);
        void addHover(std::string name, std::function<void(int, int)> func);
        void removeHover(std::string name);
        bool check(SDL_Rect hit_area, int x, int y);
        bool clicked = false;
    private:
        std::map<std::string, std::function<void(int, int)>> mouse_click_queue = {};
        std::map<std::string, std::function<void(int, int)>> mouse_hover_queue = {};
};
