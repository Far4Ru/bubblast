#include "game/components/input_name/input_name_title.hpp"

InputNameTitle::InputNameTitle() {
    text = engine->add->text("Airfool");
    text->setText("Введите имя:");
    text->x = WIDTH / 2 - 150;
    text->y = 100;
}

InputNameTitle::~InputNameTitle() {
    text->destroy();
}
