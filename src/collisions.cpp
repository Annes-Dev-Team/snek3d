#include "snek3d/collisions.hpp"

bool Snek3D::SphereCollision::collide_sphere(Snek3D::SphereCollision& other) {
    // Calculate the distance squared
    float dx = x - other.x;
    float dy = y - other.y;
    float dz = z - other.z;
    float distanceSquared = dx * dx + dy * dy + dz * dz;

    // Calculate the sum of radii squared
    float radiusSum = other.radius + other.radius;
    float radiusSumSquared = radiusSum * radiusSum;

    // Compare squared values
    return distanceSquared <= radiusSumSquared;
}
