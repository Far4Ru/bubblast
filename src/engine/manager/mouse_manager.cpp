#include "engine/manager/mouse_manager.hpp"

MouseManager::MouseManager() {

}

void MouseManager::process() {
    SDL_GetMouseState(&x,&y);
}
