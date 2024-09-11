#include "game/components/input_name/input_name_field.hpp"

InputNameField::InputNameField() {
    text = engine->add->text("Airfool");
    text->x = WIDTH / 2;
    text->y = 200;
    text->textColor = {84, 140, 47};
    timer.start();
    auto textFunc = [&]() {
        int ticks = timer.get_ticks();
        if (ticks > 150 ) {
            int strokeSize = stroke.size();
            if (strokeSize < 16) {
                stroke += engine->keyboard->getKey();
            }
            text->setText(stroke);
            text->x = WIDTH / 2 - stroke.size() * 15;
            if (strokeSize != stroke.size()) {
                timer.start();
            }
        }
    };
    text->setProcess(textFunc);
    engine->keyboard->add(SDL_SCANCODE_BACKSPACE, [&](){
        int ticks = timer.get_ticks();
        if (ticks > 150 ) {
            int strokeSize = stroke.size();
            stroke = stroke.substr(0, stroke.length() - 1);
            if (strokeSize != stroke.size()) {
                timer.start();
            }
        }
    });
}

std::string InputNameField::getName() {
    return stroke;
}

void InputNameField::setName(std::string value) {
    stroke = value;
}

InputNameField::~InputNameField() {
    timer.stop();
    text->destroy();
    engine->keyboard->remove(SDL_SCANCODE_BACKSPACE);
}