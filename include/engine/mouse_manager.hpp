#include <SDL2/SDL.h>

class MouseManager {
    public:
        MouseManager();
        void process();
        int x = 0, y = 0;
    private:
};
