#include "game/components/settings/settings_title_text.hpp"

SettingsTitleText::SettingsTitleText() {
    text = engine->add->text("WinterCat");
    text->setText("Settings");
    text->x = WIDTH / 2 - 70;
}

SettingsTitleText::~SettingsTitleText() {
    text->destroy();
}
