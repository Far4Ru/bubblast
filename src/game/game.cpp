#include "game/game.hpp"
#include "engine/engine.hpp"

extern Engine* engine;

Game::Game() {
    engine->sound->playMusic("PositiveEnergy");
    ImageObject* image = engine->add->image("bg_back");
    image->x = 50;
    engine->start();
}