#include "game/game.hpp"
#include "engine/utils/file.hpp"

ScoreText::ScoreText() {
    text = engine->add->text("Airfool");
    text->setText("Счет: " + std::to_string(game->score) + " очков");
    text->x = WIDTH / 2 - text->width / 2;
    text->y = 350;
    save();
}

void ScoreText::save() {
    bool isNew = File::init_file("results.data");
    std::ofstream data_file;
    data_file.open("results.data", std::ios_base::app);
    data_file << (isNew ? "" : "\n") + game->player_name + " - " + std::to_string(game->score);
}

ScoreText::~ScoreText() {
    text->destroy();
}