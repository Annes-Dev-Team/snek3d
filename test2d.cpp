#include "raylib/raylib.h"
#include "snek3d/CharacterModel2D.hpp"

int main() {
    InitWindow(800, 600, "2D");
    Snek3D::CharacterModel2D player;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
