#include "game/components/win/win_title.hpp"

WinTitle::WinTitle() {
    image = engine->add->image("Win");
    image->scale = 0.5;
    image->x = WIDTH / 2 - image->width * image->scale / 2;
    image->y = -image->height * image->scale / 8;
}

WinTitle::~WinTitle() {
    image->destroy();
}
