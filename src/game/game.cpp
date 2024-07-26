#include "game/game.hpp"
#include "engine/engine.hpp"

extern Engine engine;

Game::Game() {
    engine.start();
    // image = engine.add.image("wizard");
    // image.x = 50;
}