#include "game/components/results/results_title_text.hpp"

ResultsTitleText::ResultsTitleText() {
    text = engine->add->text("WinterCat");
    text->setText("Results");
    text->x = WIDTH / 2 - 70;
}

ResultsTitleText::~ResultsTitleText() {
    text->destroy();
}
