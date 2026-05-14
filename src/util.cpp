#include "snek3d/util.hpp"
#include "raylib/raylib.h"
#include <cmath>

float Snek3D::get_camera_yaw(Camera3D *cam) {

    float yaw = atan2f(cam->target.x - cam->position.x, cam->target.z - cam->position.z);

    return yaw * RAD2DEG;
}

Model Snek3D::procedure_terrain(int x, int y, int w, int h, float scale, float height) {
    Image perlin = GenImagePerlinNoise(w, h, x, y, scale);
    Mesh mesh = GenMeshHeightmap(perlin, {scale,scale,scale});
    return LoadModelFromMesh(mesh);
}
