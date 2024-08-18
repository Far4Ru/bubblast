#include "game/utils.hpp"

Utils::Utils() {

}

void Utils::calc(SDL_FPoint* first, SDL_FPoint* second, SDL_FPoint* velocity) {
    int steps = std::max(std::abs(first->x - second->x), std::abs(first->y - second->y));

    if (steps == 0) {
        velocity->x = velocity->y = 0;
        return;
    }

    velocity->x = (first->x - second->x) / steps;
    velocity->y = (first->y - second->y) / steps;
}
