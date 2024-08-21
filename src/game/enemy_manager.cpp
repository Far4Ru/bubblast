#include "game/enemy_manager.hpp"

EnemyManager::EnemyManager() {
    Enemy* enemy = new Enemy(100, 100, "candy_1");
    Enemy* enemy2 = new Enemy(1000, 1000, "candy_2");
    add(enemy);
    add(enemy2);
}

void EnemyManager::add(Enemy* enemy) {
    enemies.push_back(enemy);
}

void EnemyManager::remove(Enemy* enemy) {
    enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
}

void EnemyManager::kill(Enemy* enemy) {
    remove(enemy);
    enemy->destroy();
}
