#include "game/components/lose/lose_title.hpp"

LoseTitle::LoseTitle() {
    image = engine->add->image("lose");
    image->scale = 0.6;
    image->x = WIDTH / 2 - image->width * image->scale / 2;
    image->y = -image->height * image->scale / 6;
}

LoseTitle::~LoseTitle() {
    image->destroy();
}
