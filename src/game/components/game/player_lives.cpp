#include "game/game.hpp"

PlayerLives::PlayerLives() {
    for (int i = 0; i < MAX_PLAYER_LIVES; i++) {
        add(new PlayerLife(i));
    }
}

PlayerLives::~PlayerLives() {
    for (PlayerLife* life : lives) {
        life->destroy();
    }
    std::vector<PlayerLife*>().swap(lives);
}

void PlayerLives::reduce() {
    count--;
    if (count < 0) {
        return;
    }
    for (int i = count; i < MAX_PLAYER_LIVES; i++) {
        lives[i]->inactive();
    }
}

void PlayerLives::add(PlayerLife* life) {
    lives.push_back(life);
}

void PlayerLives::remove(PlayerLife* life) {
    lives.erase(std::remove(lives.begin(), lives.end(), life), lives.end());
}
