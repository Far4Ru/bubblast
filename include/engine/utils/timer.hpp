#include <SDL2/SDL.h>

class Timer {
    public:
        Timer();

        void start();
        void stop();
        void pause();
        void unpause();

        Uint32 get_ticks();

        bool is_started();
        bool is_paused();
    private:
        Uint32 start_ticks = 0;
        Uint32 paused_ticks = 0;

        bool paused = false;
        bool started = false;

};
