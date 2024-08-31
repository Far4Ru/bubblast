#include "game/components/logo.hpp"

Logo::Logo() {
    image = engine->add->image("logo");
    image->scale = 0.6;
    image->x = WIDTH / 2 - image->width * image->scale / 2;
    image->y = -image->height * image->scale / 6;
}

Logo::~Logo() {
    image->destroy();
}
