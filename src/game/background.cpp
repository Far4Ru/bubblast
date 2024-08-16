#include "game/background.hpp"

extern Engine* engine;

Background::Background() {
    image = engine->add->image("bg_front");
    frame = engine->add->image("bg_frame");
}
