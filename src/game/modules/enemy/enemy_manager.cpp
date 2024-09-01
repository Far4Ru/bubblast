#include "game/modules/enemy/enemy_manager.hpp"

EnemyManager::EnemyManager() {
    timer.start();
    std::srand(std::time(nullptr));
    TimeObject* time = engine->add->time();
    auto timeFunc = [&]() {
        int ticks = timer.get_ticks();
        if (ticks > 1000) {
            if (game_seconds % 100 == 0) {
                int enemy_number = rand() % (5 - 1 + 1) + 1;
                int side = std::rand() / ((RAND_MAX + 1u) / 4);
                int x = 0, y = 0;
                switch (side) {
                    case 0:
                        x = -(std::rand() / ((RAND_MAX + 1u) / 50));
                        y = std::rand() / ((RAND_MAX + 1u) / 1200);
                        break;
                    case 1:
                        x = 1900 + (std::rand() / ((RAND_MAX + 1u) / 50));
                        y = std::rand() / ((RAND_MAX + 1u) / 1200);
                        break;
                    case 2:
                        x = 1200 + std::rand() / ((RAND_MAX + 1u) / 100);
                        y = std::rand() / ((RAND_MAX + 1u) / 700);
                        break;
                    case 3:
                        x = std::rand() / ((RAND_MAX + 1u) / 1200);
                        y = 700 + std::rand() / ((RAND_MAX + 1u) / 100);
                        break;
                }
                std::string enemy_prefix = "candy_";
                std::string enemy_name = enemy_prefix + std::to_string(enemy_number);
                Enemy* enemy = new Enemy(x, y, enemy_name);
                add(enemy);
            }
            game_seconds++;
            timer.start();
        }
    };
    time->setProcess(timeFunc);
}

EnemyManager::~EnemyManager() {
    timer.stop();
    killAll();
}

std::string EnemyManager::getTime() {
    int game_seconds_display = 5 * 60 - game_seconds;
    std::string seconds = std::to_string(game_seconds_display % 60);
    std::string minutes = std::to_string(game_seconds_display / 60);
    return (minutes.length() > 1 ? "" : "0") + minutes + ":" + (seconds.length() > 1 ? "" : "0") + seconds;
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

void EnemyManager::killAll() {
    for (Enemy* enemy : enemies) {
        enemy->destroy();
    }
    std::vector<Enemy*>().swap(enemies);
}
