#include "game/bullet.hpp"

Bullet::Bullet() {
    ImageObject* bullet = engine->add->image("bullet_bubble");
    bullet->scale = 0.1;
}
