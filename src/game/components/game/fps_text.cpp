#include "game/components/game/fps_text.hpp"

FPSText::FPSText() {
    fps_text = engine->add->text("WinterCat");
    auto textFunc = [&]() {
        fps_text->setText(engine->fps->get() + " FPS");
    };
    fps_text->setProcess(textFunc);
    fps_text->x = WIDTH - 200;
    fps_text->y = 0;
}

FPSText::~FPSText() {
    fps_text->destroy();
}
