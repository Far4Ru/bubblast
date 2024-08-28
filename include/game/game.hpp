#ifndef GAME_H
#define GAME_H

#include "engine/engine.hpp"
#include "game/background.hpp"
#include "game/player.hpp"
#include "game/sound.hpp"
#include "game/fps_text.hpp"
#include "game/mouse_text.hpp"
#include "game/screen_text.hpp"
#include "game/bullet_manager.hpp"
#include "game/enemy_manager.hpp"

class Game {
    public:
        Game();
        void start();

        Player* player;
        Sound* sound;
        BulletManager* bullet_manager;
        EnemyManager* enemy_manager;
};

extern Game* game;

#endif