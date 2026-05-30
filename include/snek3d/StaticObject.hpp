#include "raylib/raylib.h"

namespace Snek3D {
    struct StaticObject {
        Model* model;
        float x;
        float y;
        float z;
        float scale;
        Color tint;

        void draw();
        StaticObject(Model* emodel, float x = 0, float y = 0, float z = 0, float scale = 1, Color tint=WHITE);
        StaticObject(const char* path, float x = 0, float y = 0, float z = 0, float scale = 1, Color tint=WHITE);
    };
}
