#include "engine/manager/fps.hpp"

FPS::FPS() {
    fpsTimer.start();
}

std::string FPS::get() {
    return value;
}

void FPS::start() {
    capTimer.start();
    float avgFPS = countedFrames / ( fpsTimer.get_ticks() / 1000.f );
    if (avgFPS > 2000000) {
        avgFPS = 0;
    }
    value = std::to_string(avgFPS);
}

void FPS::end() {
    ++countedFrames;
    int frameTicks = capTimer.get_ticks();
    if (frameTicks < 1000 / 60) {
        SDL_Delay(1000 / 60 - frameTicks);
    }
}
