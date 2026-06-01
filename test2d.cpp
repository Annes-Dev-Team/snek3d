#include "raylib/raylib.h"
#include "snek3d/Player2D.hpp"

int main() {
    InitWindow(800, 600, "2D");
    Snek3D::Player2D player("assets/dragon");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        player.update(5, 5);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
