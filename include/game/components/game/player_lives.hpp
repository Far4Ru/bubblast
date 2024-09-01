#include "game/components/game/player_life.hpp"

class PlayerLives {
    public:
        PlayerLives();
        ~PlayerLives();

        void add(PlayerLife* life);
        void remove(PlayerLife* life);
    private:
        std::vector<PlayerLife*> lives;
};
