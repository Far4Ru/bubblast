#include "game/game.hpp"

GameTimeText::GameTimeText() {
    text = engine->add->text("WinterCat");
    auto textFunc = [&]() {
        text->setText(game->gameScene->enemy_manager->getTime());
    };
    text->setProcess(textFunc);
    text->x = 200;
    text->y = 0;
}

GameTimeText::~GameTimeText() {
    text->destroy();
}
