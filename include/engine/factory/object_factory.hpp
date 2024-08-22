#include "engine/renderer.hpp"
#include "engine/loader/loader.hpp"
#include "engine/render_object/time_object.hpp"

class ObjectFactory {
    public:
        ObjectFactory(Renderer* renderer, Loader* loader);
        ImageObject* image(std::string name);
        TextObject* text(std::string name);
        TimeObject* time();
    private:
        Renderer* renderer = NULL;
        Loader* loader = NULL;
};
