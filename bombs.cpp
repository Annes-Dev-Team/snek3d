#include "raylib/raylib.h"
#include "snek3d/CharacterModel.hpp"

int main() {
    Camera3D camera = {
        .position = {0, 0 , -2},
        .target = {0,0,0},
        .up = {0,1,0},
        .fovy = 60,
        .projection = CAMERA_PERSPECTIVE
    };
    int winw;
    int winh;
    InitWindow(800, 600, "Bombs");
    SetTargetFPS(60);
    Snek3D::CharacterModel player("assets/chick.glb");
    float x = 0;
    
    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_CUSTOM);
        player.current_animation = player.walkanim;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.update();
        BeginMode3D(camera);
        
        player.draw(x, -1);
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
}
