#include "snek3d/util.hpp"
#include "raylib/raylib.h"
#include <cmath>
#include <utility>

float Snek3D::get_camera_yaw(Camera3D *cam) {

    float yaw = atan2f(cam->target.x - cam->position.x, cam->target.z - cam->position.z);

    return yaw * RAD2DEG;
}

Model Snek3D::procedure_terrain(int x, int y, int w, int h, float scale, float height) {
    Image perlin = GenImagePerlinNoise(w, h, x, y, scale);
    Mesh mesh = GenMeshHeightmap(perlin, {scale,scale,scale});
    return LoadModelFromMesh(mesh);
}

float Snek3D::get_random_float(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

BoundingBox Snek3D::make_bounding_box(float x, float y, float z,
                                       float width, float height, float length) {
    float minX = x;
    float minY = y;
    float minZ = z;

    float maxX = x + width;
    float maxY = y + height;
    float maxZ = z + length;

    // fix negative sizes
    if (maxX < minX) std::swap(minX, maxX);
    if (maxY < minY) std::swap(minY, maxY);
    if (maxZ < minZ) std::swap(minZ, maxZ);

    return {
        .min = {minX, minY, minZ},
        .max = {maxX, maxY, maxZ}
    };
}
