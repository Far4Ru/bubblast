#include "engine/engine.hpp"

class SoundSettings {
    public:
        SoundSettings();
        ~SoundSettings();
    private:
        TextObject* title;
        TextObject* left;
        TextObject* value_text;
        TextObject* right;
        int value = 100;
};