#ifndef SETTINGS_SCENE_H
#define SETTINGS_SCENE_H

#include "engine/engine.hpp"
#include "game/scenes/scene_base.hpp"
#include "game/components/settings/settings_title_text.hpp"
#include "game/components/settings/fullscreen_settings.hpp"
#include "game/components/settings/sound_settings.hpp"
#include "game/components/settings/music_settings.hpp"

class SettingsScene : public SceneBase {
    public:
        SettingsScene();

        void clear();
        void start();
    private:
        bool active = false;
        MenuBackground* background;
        SettingsTitleText* title;
        BackMenuButton* back_to_menu;
        FullscreenSettings* fullscreen_settings;
        SoundSettings* sound_settings;
        MusicSettings* music_settings;
};

#endif
