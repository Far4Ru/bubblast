#include "game/background.hpp"

Background::Background() {
    image = engine->add->image("bg_front");
    frame = engine->add->image("bg_frame");
    auto imageFunc = [&]() {
        image->setOffset(-engine->camera->x , -engine->camera->y );
    };
    image->setProcess(imageFunc);
    auto frameFunc = [&]() {
        frame->setOffset(-engine->camera->x , -engine->camera->y );
    };
    frame->setProcess(frameFunc);
}
