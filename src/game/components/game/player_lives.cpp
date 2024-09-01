#include "game/components/game/player_lives.hpp"

PlayerLives::PlayerLives() {
    for (int i = 0; i < 3; i++) {
        add(new PlayerLife(i));
    }
    lives[2]->inactive();
}

PlayerLives::~PlayerLives() {
    for (PlayerLife* life : lives) {
        life->destroy();
    }
    std::vector<PlayerLife*>().swap(lives);
}

void PlayerLives::add(PlayerLife* life) {
    lives.push_back(life);
}

void PlayerLives::remove(PlayerLife* life) {
    lives.erase(std::remove(lives.begin(), lives.end(), life), lives.end());
}
