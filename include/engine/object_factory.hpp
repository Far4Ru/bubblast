#include "engine/renderer.hpp"
#include "engine/loader/loader.hpp"

class ObjectFactory {
    public:
        ObjectFactory(Renderer* renderer, Loader* loader);
        ImageObject* image(std::string name);
        TextObject* text(std::string name);
    private:
        Renderer* renderer = NULL;
        Loader* loader = NULL;
};
