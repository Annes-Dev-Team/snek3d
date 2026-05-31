#include <raylib/raylib.h>
#include <string>
#include <vector>
#pragma once

namespace Snek3D {
    struct Animation {
        std::string name;
        std::vector<Texture2D*> frames;
    };
    struct CharacterModel2D {
        int animframe = 0;

        std::vector<Animation> animations;

        std::vector<Texture2D*>* walkanim = nullptr;
        std::vector<Texture2D*>* runanim = nullptr;
        std::vector<Texture2D*>* idleanim = nullptr;
        std::vector<Texture2D*>* sitanim = nullptr;
        std::vector<Texture2D*>* swimanim = nullptr;
        std::vector<Texture2D*>* climbanim = nullptr;

        std::vector<Texture2D*>* current_animation = nullptr;

        CharacterModel2D(const std::string& path);
        CharacterModel2D();

        /* load a folder of numbered images
            example:
            
                load_animations("swim");

                swim/
                    0.png
                    1.png
            */
        void load_animations(const std::string& path);

        std::vector<Texture2D*>* find_animation(const std::string& name);

        void update();

        void draw(
            float x = 0,
            float y = 0,
            float scale = 1,
            Color tint = WHITE);

        void draw_advanced(
            float x = 0,
            float y = 0,
            float rot = 0,
            Vector2 scale = {1,1},
            Color tint = WHITE);
    };
}
