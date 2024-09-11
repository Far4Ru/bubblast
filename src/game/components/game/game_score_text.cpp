#include "game/game.hpp"

GameScoreText::GameScoreText() {
    text = engine->add->text("Airfool");
    text->x = 45;
    text->y = 90;
    auto textFunc = [&]() {
        text->setText("Счет: " + std::to_string(game_score));
    };
    text->setProcess(textFunc);
}

GameScoreText::~GameScoreText() {
    text->destroy();
}
