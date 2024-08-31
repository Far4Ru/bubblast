#include "game/game.hpp"

MenuBackground::MenuBackground() {
    image = engine->add->image("bg_back");
    image->scale = (float)2/3;
}

MenuBackground::~MenuBackground() {
    image->destroy();
}
