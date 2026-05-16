#include "raylib/raylib.h"
namespace Snek3D {
    float get_camera_yaw(Camera3D* cam); // get camera yaw in degrees

    Model procedure_terrain(int x=0, int y=0, int w=20, int h=20, float scale=3, float height=0.4);
    float get_random_float(float min, float max);
    BoundingBox make_bounding_box(float x, float y, float z, float width, float height, float length);
}
