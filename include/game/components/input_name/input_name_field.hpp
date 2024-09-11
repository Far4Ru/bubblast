#include "engine/engine.hpp"

class InputNameField {
    public:
        InputNameField();
        ~InputNameField();

        void setName(std::string value);
        std::string getName();
    private:
        Timer timer;
        std::string stroke;
        TextObject* text;
};
