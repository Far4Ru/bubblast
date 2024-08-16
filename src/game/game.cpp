#include "game/game.hpp"

Game::Game() {
    Background* background = new Background();
    Player* player = new Player();
    Sound* sound = new Sound();
    TextObject* fps_text = engine->add->text("WinterCat");
    auto textFunc = [&]() {
        fps_text->setText(engine->fps->get() + " FPS");
    };
    fps_text->setProcess(textFunc);
    fps_text->x = 200;
    fps_text->y = 0;
    TextObject* mouse_text = engine->add->text("WinterCat");
    auto mouse_text_func = [&]() {
        mouse_text->setText("Mouse:" + std::to_string(engine->mouse->x) + ":" + std::to_string(engine->mouse->x));
    };
    mouse_text->setProcess(mouse_text_func);
    mouse_text->x = 400;
    mouse_text->y = 0;
    engine->start();
}