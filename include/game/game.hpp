#ifndef GAME_H
#define GAME_H

#include "engine/engine.hpp"
#include "game/scenes/game_scene.hpp"
#include "game/scenes/menu_scene.hpp"
#include "game/scenes/lose_scene.hpp"
#include "game/scenes/results_scene.hpp"
#include "game/scenes/settings_scene.hpp"
#include "game/scenes/win_scene.hpp"
#include "game/scenes/scene_base.hpp"
#include "game/scenes/input_name_scene.hpp"


class Game {
    public:
        Game();

        std::string player_name = "";
        int score = 0;
        int game_seconds = 0;

        void start();

        MenuScene* menuScene;
        GameScene* gameScene;
        ResultsScene* resultsScene;
        SettingsScene* settingsScene;
        WinScene* winScene;
        LoseScene* loseScene;
        InputNameScene* inputNameScene;

        void change_scene(SceneBase* scene);
    private:
        SceneBase* current_scene = NULL;
};

extern Game* game;

#endif