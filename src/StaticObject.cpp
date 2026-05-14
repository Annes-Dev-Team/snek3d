#include "snek3d/StaticObject.hpp"
#include "raylib/raylib.h"

void Snek3D::StaticObject::draw() {
    DrawModel(model, {x,y,z}, scale, tint);
}

Snek3D::StaticObject::StaticObject(std::string path, float xp , float yp , float zp , float scalef , Color tintc) {
    model = LoadModel(path.c_str());
    x =xp;
    y = yp;
    z = zp;
    scale = scalef;
    tint = tintc;
}
