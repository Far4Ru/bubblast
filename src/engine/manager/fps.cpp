#include "engine/manager/fps.hpp"

FPS::FPS() {

}

std::string FPS::get() {
    return value;
}

bool FPS::tick() {
    Uint32 a = SDL_GetTicks();
    Uint32 delta = a - b;
    bool isTick = delta > 1000 / 60;
    if (isTick) {
        b = a;
        value = std::to_string(1000 / delta);
    }
    return isTick;
}
