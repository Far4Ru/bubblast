#include "game/components/results/results_title_text.hpp"

ResultsTitleText::ResultsTitleText() {
    text = engine->add->text("Airfool");
    text->setText("Результаты");
    text->x = WIDTH / 2 - 70;
    text->y = 100;
}

ResultsTitleText::~ResultsTitleText() {
    text->destroy();
}
