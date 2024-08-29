#include "config/config.hpp"
#include "engine/entity/render_object/image_object.hpp"

class CameraManager {
    public:
        CameraManager();
        int x = 0, y = 0;
        int width = 0, height = 0;
        void process();
        void follow(ImageObject* object);
    private:
        ImageObject* follow_object;
};
