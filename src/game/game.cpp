#include "game/game.hpp"
#include "engine/engine.hpp"

extern Engine engine;

Game::Game() {
    engine.run();
}