#include "engine/engine.hpp"

class GameScoreText {
    public:
        GameScoreText();
        ~GameScoreText();
        int game_score = 0;
    private:
        TextObject* text;
};
