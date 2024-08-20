#ifndef COLLISION_OBJECT_H
#define COLLISION_OBJECT_H

class CollisionObject {
    public:
        virtual void updateVelocity() = 0;
        virtual ~CollisionObject() = default;
};

#endif