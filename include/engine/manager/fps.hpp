#include <SDL2/SDL.h>
#include <iostream>

class FPS {
    public:
        FPS();

        std::string get();
        bool tick();
    private:
        Uint32 b = 0;
        std::string value = "";
};
