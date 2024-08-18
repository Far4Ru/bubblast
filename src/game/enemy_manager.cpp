#include "game/enemy_manager.hpp"

EnemyManager::EnemyManager() {
    Enemy* enemy = new Enemy(100, 100);
    timer.start();
    int ticks = timer.get_ticks();
    if (ticks > 10 * (1000 / 60)) {
        enemy->updateVelocity();
        timer.start();
    }
}
