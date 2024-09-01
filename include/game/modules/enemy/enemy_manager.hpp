#include <cstdlib>
#include <ctime>

#include "game/modules/enemy/enemy.hpp"

class EnemyManager {
    public:
        EnemyManager();
        ~EnemyManager();

        void kill(Enemy* enemy);
        void killAll();
        void add(Enemy* enemy);
        void remove(Enemy* enemy);
        std::string getTime();
    private:
        int game_seconds = 0;
        Timer timer;
        std::vector<Enemy*> enemies;
};
