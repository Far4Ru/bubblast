#include "game/game.hpp"
#include "engine/engine.hpp"

extern Engine* engine;

Game::Game() {
    engine->sound->playMusic("PositiveEnergy");
    ImageObject* image = engine->add->image("wizard");
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
    image->x = 50;
    engine->keyboard->add(SDL_SCANCODE_UP, [&]() {
        image->y -= 10;
    });
    engine->keyboard->add(SDL_SCANCODE_W, [&]() {
        image->y -= 10;
    });
    engine->keyboard->add(SDL_SCANCODE_DOWN, [&]() {
        image->y += 10;
    });
    engine->keyboard->add(SDL_SCANCODE_S, [&]() {
        image->y += 10;
    });
    engine->keyboard->add(SDL_SCANCODE_LEFT, [&]() {
        image->x -= 10;
        image->turnLeft();
    });
    engine->keyboard->add(SDL_SCANCODE_A, [&]() {
        image->x -= 10;
        image->turnLeft();
    });
    engine->keyboard->add(SDL_SCANCODE_RIGHT, [&]() {
        image->x += 10;
        image->turnRight();
    });
    engine->keyboard->add(SDL_SCANCODE_D, [&]() {
        image->x += 10;
        image->turnRight();
    });
    engine->keyboard->add(SDL_SCANCODE_SPACE, [&]() {
        engine->sound->playSound("BubbleSpell");
    });
    engine->keyboard->add(SDL_SCANCODE_1, [&]() {
        engine->sound->pauseMusic();
    });
    engine->keyboard->add(SDL_SCANCODE_2, [&]() {
        engine->sound->resumeMusic();
    });
    engine->start();
}