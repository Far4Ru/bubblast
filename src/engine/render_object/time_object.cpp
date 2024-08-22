#include "engine/render_object/time_object.hpp"

TimeObject::TimeObject() {

}

TimeObject::~TimeObject() {

}

bool TimeObject::load(SDL_Renderer* renderer, SDL_Surface* imageSurface) {
    return true;
}

void TimeObject::destroy() {
    this->~TimeObject();
}

void TimeObject::process() {
    if (process_function) {
        process_function();
    }
}

void TimeObject::setProcess(std::function<void()> func) {
    process_function = func;
}

void TimeObject::render(SDL_Renderer* renderer) {
    
}
