#ifndef GAME_H
#define GAME_H

#include "engine/engine.hpp"
#include "game/scenes/game_scene.hpp"
#include "game/scenes/menu_scene.hpp"

class Game {
    public:
        Game();
        void start();

        MenuScene* menuScene;
        GameScene* gameScene;
};

extern Game* game;

#endif