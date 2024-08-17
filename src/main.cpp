#include "engine/engine.hpp"
#include "game/game.hpp"

Engine* engine = new Engine();
Game* game = new Game();

int main(int argc, char *argv[]) {
    game->start();
    return EXIT_SUCCESS;
}