#include "game/enemy_manager.hpp"

EnemyManager::EnemyManager() {
    Enemy* enemy = new Enemy(100, 100, "candy_1");
    Enemy* enemy2 = new Enemy(1000, 1000, "candy_2");
}
