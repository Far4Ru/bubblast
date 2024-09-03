#include "config/config.hpp"
#include "engine/entity/render_object/image_object.hpp"

class SceneManager {
    public:
        SceneManager();
        void process();
        void set(std::function<void()> func);
        void unset();
    private:
        std::function<void()> scene_switch_handler = NULL;
};
