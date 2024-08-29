#ifndef GAME_H
#define GAME_H

#include "engine/engine.hpp"
#include "game/components/background.hpp"
#include "game/modules/player/player.hpp"
#include "game/modules/sound/sound.hpp"
#include "game/components/fps_text.hpp"
#include "game/components/mouse_text.hpp"
#include "game/components/screen_text.hpp"
#include "game/modules/bullet/bullet_manager.hpp"
#include "game/modules/enemy/enemy_manager.hpp"

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