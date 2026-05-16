#include "raylib/raylib.h"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <snek3d/CharacterModel.hpp>
#include <string>

void Snek3D::CharacterModel::load_animations(const std::string path) {
    const char* charpath = path.c_str();
    int animcount = 0;
    ModelAnimation* anime = LoadModelAnimations(charpath, &animcount);

    animations.clear();

    for (int i = 0; i < animcount; i++) {
        animations.push_back(&anime[i]);
    }
    
    walkanim = find_animation("walk");
    runanim = find_animation("run");
    idleanim = find_animation("idle");

    sitanim = find_animation("sit");
    swimanim = find_animation("swim");
    climbanim = find_animation("climb");

}

ModelAnimation* Snek3D::CharacterModel::find_animation(const std::string name) {
    const char* nemc = name.c_str();
    for (size_t i = 0; i < animations.size(); i++) {
        ModelAnimation* ere = animations[i];
        if (std::strcmp(ere->name, nemc) == 0) {
            return ere;
        }
    }
    return nullptr;
}

void Snek3D::CharacterModel::update() {
    if (!current_animation) {
        return;
    }

    if (!IsModelValid(model)) {
        return;
    }

    if (!IsModelAnimationValid(model, *current_animation)) {
        return;
    }
    animframe++;

    if (animframe >= current_animation->keyframeCount) {
        animframe = 0;
    }

    UpdateModelAnimation(model, *current_animation, animframe);
}

void Snek3D::CharacterModel::draw(float x, float y, float z, float scale, Color tint) {
    DrawModel(model, {x,y,z}, scale, tint);
}

void Snek3D::CharacterModel::draw_advanced(float x, float y, float z, Vector3 axis, float rot, Vector3 scale, Color tint) {
    DrawModelEx(model, {x,y,z}, axis, rot, scale, tint);
}

void Snek3D::CharacterModel::load_model(const std::string path) {
    const char* charpath = path.c_str();
    model = LoadModel(charpath);
}

Snek3D::CharacterModel::CharacterModel(const std::string path) {
    load_model(path);
    load_animations(path);
    std::cout << "New CharacterModel " << this << std::endl;
}

Snek3D::CharacterModel::CharacterModel() {
    std::cout << "Possibly Unitialized CharacterModel " << this << std::endl;
}
