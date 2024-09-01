#include "engine/engine.hpp"

class PlayerLife {
    public:
        PlayerLife(int number);
        ~PlayerLife();

        void inactive();
        void destroy();
    private:
        ImageObject* image;
        ImageObject* image_inactive;
};
