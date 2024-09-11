#ifndef SCORE_TEXT_H
#define SCORE_TEXT_H

#include "engine/engine.hpp"

class ScoreText {
    public:
        ScoreText();
        ~ScoreText();
    private:
        TextObject* text;
        void save();
};

#endif
