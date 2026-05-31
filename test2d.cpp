#include "raylib/raylib.h"
#include "snek3d/CharacterModel2D.hpp"

int main() {
    InitWindow(800, 600, "2D");
    Snek3D::CharacterModel2D player("assets/dragon");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        player.update(5);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
