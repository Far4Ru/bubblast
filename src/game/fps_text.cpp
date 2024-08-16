#include "game/fps_text.hpp"

FPSText::FPSText() {
    TextObject* fps_text = engine->add->text("WinterCat");
    auto textFunc = [&, fps_text]() {
        fps_text->setText(engine->fps->get() + " FPS");
    };
    fps_text->setProcess(textFunc);
    fps_text->x = 200;
    fps_text->y = 0;
}
