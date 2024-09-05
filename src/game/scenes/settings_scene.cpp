#include "game/game.hpp"

SettingsScene::SettingsScene() {

}

void SettingsScene::clear() {
    if (this->active) {
        this->active = false;
        engine->renderer->clear();
        delete background;
        delete title;
        delete back_to_menu;
        delete fullscreen_settings;
        delete music_settings;
        delete sound_settings;
        engine->keyboard->remove(SDL_SCANCODE_ESCAPE);
    }
}

void SettingsScene::start() {
    if (!this->active) {
        this->active = true;
        background = new MenuBackground();
        title = new SettingsTitleText();
        back_to_menu = new BackMenuButton();
        fullscreen_settings = new FullscreenSettings();
        music_settings = new MusicSettings();
        sound_settings = new SoundSettings();
        // InputHelp
        engine->scene->set([&]() {
            if (back_to_menu->pressed) {
                game->change_scene(game->menuScene);
            }
        });
        
        engine->keyboard->add(SDL_SCANCODE_ESCAPE, [&]() {
            game->change_scene(game->menuScene);
        });
    }
}