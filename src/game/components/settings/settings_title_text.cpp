#include "game/components/settings/settings_title_text.hpp"

SettingsTitleText::SettingsTitleText() {
    text = engine->add->text("Airfool");
    text->setText("Настройки");
    text->x = WIDTH / 2 - 70;
    text->y = 100;
}

SettingsTitleText::~SettingsTitleText() {
    text->destroy();
}
