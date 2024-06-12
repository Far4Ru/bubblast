#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "engine/keyboard.hpp"
#include "engine/mouse.hpp"

/**
 * 
*/
class Input {
    public:
        Input();
        Keyboard keyboard;
        Mouse mouse;
    private:
};