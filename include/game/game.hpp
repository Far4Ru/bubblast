#ifndef GAME_H
#define GAME_H

#include "engine/engine.hpp"
#include "game/scenes/game_scene.hpp"
#include "game/scenes/menu_scene.hpp"
#include "game/scenes/lose_scene.hpp"
#include "game/scenes/results_scene.hpp"
#include "game/scenes/settings_scene.hpp"
#include "game/scenes/win_scene.hpp"


class Game {
    public:
        Game();
        void start();

        MenuScene* menuScene;
        GameScene* gameScene;
        ResultsScene* resultsScene;
        SettingsScene* settingsScene;
        WinScene* winScene;
        LoseScene* loseScene;
};

extern Game* game;

#endif