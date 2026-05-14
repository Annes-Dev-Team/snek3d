#include "raylib/raylib.h"
#include "snek3d/CharacterModel.hpp"

namespace Snek3D {
    // idle, walk, sit, and run animations recommended
    struct Player {
        CharacterModel cmodel;
        Camera3D camera = {
            .position = {1, 2, 0},
            .target = {0,0,0},
            .up = {0,1,0},
            .fovy = 60,
            .projection = CAMERA_PERSPECTIVE
        };
        float x;
        float y;
        float z;
        float scale;
        float rot;
        Color tint;
        Vector3 head_offset;

        bool can_run=0;
        bool can_sit=0;

        bool is_moving=0;

        Player(const std::string path, float xpos=0, float ypos=0, float zpos=0, float scalee=1, Color tintt=WHITE, Vector3 headoffset={0, 2, 0});
        void begin_perspective(bool flip=true);
        void draw();
        void end_perspective();
    };
}
