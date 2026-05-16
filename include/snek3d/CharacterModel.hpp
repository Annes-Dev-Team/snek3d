#include <raylib/raylib.h>
#include <string>
#include <vector>
#pragma once

namespace Snek3D {
    struct CharacterModel {
        Model model;
        int animframe = 0;
        std::vector<ModelAnimation*> animations;

        ModelAnimation* walkanim;
        ModelAnimation* runanim;
        ModelAnimation* idleanim;
        ModelAnimation* sitanim;

        ModelAnimation* swimanim;
        ModelAnimation* climbanim;

        ModelAnimation* current_animation;

        CharacterModel(const std::string path);
        CharacterModel();
        
        void load_animations(const std::string path);
        void load_model(const std::string path);
        ModelAnimation* find_animation(const std::string name);
        void update();
        void draw(float x=0, float y=0, float z=0, float scale=1, Color tint=WHITE);
        //DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
        void draw_advanced(float x=0, float y=0, float z=0, Vector3 axis={0,1,0}, float rot=0, Vector3 scale={1,1,1}, Color tint=WHITE);
    };
}
