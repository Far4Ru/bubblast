#include "game/components/game/screen_text.hpp"

ScreenText::ScreenText() {
    screen_text = engine->add->text("WinterCat");
    auto textFunc = [&]() {
        std::string widthText = std::to_string(engine->game_area->width);
        std::string heightText = std::to_string(engine->game_area->height);
        std::string full_widthText = std::to_string(engine->game_area->full_width);
        std::string full_heightText = std::to_string(engine->game_area->full_height);
        std::string cameraTextX = std::to_string(engine->camera->x);
        std::string cameraTextY = std::to_string(engine->camera->y);
        screen_text->setText("Screen: " + widthText + ":" + heightText + " - " + full_widthText + ":" + full_heightText + " | " + cameraTextX + ":" + cameraTextY);
    };
    screen_text->setProcess(textFunc);
    screen_text->x = 200;
    screen_text->y = 50;
}

ScreenText::~ScreenText() {
    screen_text->destroy();
}