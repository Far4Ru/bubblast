#include "game/components/game/mouse_text.hpp"

MouseText::MouseText() {
    mouse_text = engine->add->text("Airfool");
    auto mouse_text_func = [&]() {
        return;
        mouse_text->setText("Mouse:" + std::to_string(engine->mouse->x) + ":" + std::to_string(engine->mouse->y));
    };
    mouse_text->setProcess(mouse_text_func);
    mouse_text->x = 400;
    mouse_text->y = 0;
}

MouseText::~MouseText() {
    mouse_text->destroy();
}