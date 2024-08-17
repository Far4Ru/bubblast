#include "engine/engine.hpp"
 
class Player {
    public:
        Player();
        int x = 0, y = 0;
    private:
        ImageObject* player;
        void update();
};
