#include "engine/render_object/render_object.hpp"

class CameraManager {
    public:
        CameraManager();
        int x;
        int y;
        void process();
        void follow(RenderObject* object);
    private:
        RenderObject* follow_object = NULL;
};
