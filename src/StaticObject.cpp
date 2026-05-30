#include "snek3d/StaticObject.hpp"
#include "raylib/raylib.h"

void Snek3D::StaticObject::draw() {
    DrawModel(*model, {x,y,z}, scale, tint);
}

Snek3D::StaticObject::StaticObject(Model* emodel, float xp , float yp , float zp , float scalef , Color tintc) {
    model = emodel;
    x =xp;
    y = yp;
    z = zp;
    scale = scalef;
    tint = tintc;
}

Snek3D::StaticObject::StaticObject(const char* path, float xp , float yp , float zp , float scalef , Color tintc) {
    model = new Model{LoadModel(path)};
    x =xp;
    y = yp;
    z = zp;
    scale = scalef;
    tint = tintc;
}
