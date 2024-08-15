#include "engine/object_factory.hpp"

ObjectFactory::ObjectFactory(Renderer* renderer, Loader* loader) {
    this->renderer = renderer;
    this->loader = loader;
}

ImageObject* ObjectFactory::image(std::string name) {
    ImageObject* image = new ImageObject();
    image->load(renderer->get(), loader->getImage(name));
    renderer->add(image);
    return image;
}

TextObject* ObjectFactory::text(std::string name) {
    TextObject* text = new TextObject();
    text->setFont(loader->getFont(name));
    renderer->add(text);
    return text;
}
