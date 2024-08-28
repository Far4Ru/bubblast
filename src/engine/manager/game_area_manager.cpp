#include "engine/manager/game_area_manager.hpp"

GameAreaManager::GameAreaManager() {
    
}

void GameAreaManager::resize(SDL_Renderer* renderer, Window* window) {
    /** viewport resizing */
    SDL_Rect viewport;
    full_width = window->width;
    full_height = window->height;
    viewport.x = 0;
    viewport.y = 0;
    width = full_height * ((float)WIDTH / HEIGHT);
    height = full_width * ((float)HEIGHT / WIDTH);
    if (full_width - width > full_height - height) {
        height = full_height;
        viewport.x = full_width / 2 - (float)width / 2;
    } else {
        width = full_width;
        viewport.y = full_height / 2 - (float)height / 2;
    }
    viewport.w = width;
    viewport.h = height;
    SDL_RenderSetViewport(renderer, &viewport);
}