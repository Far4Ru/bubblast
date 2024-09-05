#include "engine/engine.hpp"

class FullscreenSettings {
    public:
        FullscreenSettings();
        ~FullscreenSettings();
    private:
        TextObject* title;
        TextObject* left;
        TextObject* value;
        TextObject* right;
};