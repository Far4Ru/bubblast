#include "game/mouse_text.hpp"

MouseText::MouseText() {
    TextObject* mouse_text = engine->add->text("WinterCat");
    auto mouse_text_func = [&, mouse_text]() {
        mouse_text->setText("Mouse:" + std::to_string(engine->mouse->x) + ":" + std::to_string(engine->mouse->x));
    };
    mouse_text->setProcess(mouse_text_func);
    mouse_text->x = 400;
    mouse_text->y = 0;
}
