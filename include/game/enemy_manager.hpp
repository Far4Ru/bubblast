#include "game/enemy.hpp"

class EnemyManager {
    public:
        EnemyManager();
        void kill(Enemy* enemy);
        void add(Enemy* enemy);
        void remove(Enemy* enemy);
    private:
        Timer timer;
        std::vector<Enemy*> enemies;
};
