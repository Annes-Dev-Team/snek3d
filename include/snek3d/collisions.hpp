

namespace Snek3D {
    enum CollisionEntry {
        BOX_COLLISION,
        CAPSULE_COLLISION,
        SPHERE_COLLISION
    };

    struct SphereCollision {
        float x, y, z;
        float radius;

        bool collide_sphere(SphereCollision& other);
    };
}
