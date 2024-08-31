#include "engine/window.hpp"

class GameAreaManager {
    public:
        GameAreaManager();
        void resize(SDL_Renderer* renderer, Window* window);
        int height = 0, width = 0;
        float scale = 1;
        int full_height = 0, full_width = 0;
        int x = 0, y = 0;
};
