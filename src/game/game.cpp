#include "game/game.hpp"
#include "engine/engine.hpp"

extern Engine* engine;

Game::Game() {
    engine->sound->playMusic("PositiveEnergy");
    ImageObject* bg_front = engine->add->image("bg_front");
    ImageObject* bg_back = engine->add->image("bg_frame");
    ImageObject* player = engine->add->image("wizard");
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
    player->x = 50;
    player->scale = 0.25;
    engine->keyboard->add(SDL_SCANCODE_UP, [&]() {
        if (player->y > 0) {
            player->y -= 10;
        }
    });
    engine->keyboard->add(SDL_SCANCODE_W, [&]() {
        if (player->y > 0) {
            player->y -= 10;
        }
    });
    engine->keyboard->add(SDL_SCANCODE_DOWN, [&]() {
        if (player->y < HEIGHT) {
            player->y += 10;
        }
    });
    engine->keyboard->add(SDL_SCANCODE_S, [&]() {
        if (player->y < HEIGHT) {
            player->y += 10;
        }
    });
    engine->keyboard->add(SDL_SCANCODE_LEFT, [&]() {
        if (player->x > 0) {
            player->x -= 10;
            player->turnLeft();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_A, [&]() {
        if (player->x > 0) {
            player->x -= 10;
            player->turnLeft();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_RIGHT, [&]() {
        if (player->x < WIDTH) {
            player->x += 10;
            player->turnRight();
        }
    });
    engine->keyboard->add(SDL_SCANCODE_D, [&]() {
        if (player->x < WIDTH) {
            player->x += 10;
            player->turnRight();
        }
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