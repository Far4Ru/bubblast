#include "engine/engine.hpp"

class MusicSettings {
    public:
        MusicSettings();
        ~MusicSettings();
    private:
        TextObject* title;
        TextObject* left;
        TextObject* value_text;
        TextObject* right;
        int value = 100;
};