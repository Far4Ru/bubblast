#include "engine/engine.hpp"

class GameTimeText {
    public:
        GameTimeText();
        ~GameTimeText();
        int game_seconds = 0;
    private:
        Timer timer;
        std::string getTime();
        TextObject* text;
};
