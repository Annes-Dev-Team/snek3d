#include "raylib/raylib.h"
#include <snek3d/CharacterModel.hpp>
#include <snek3d/Player.hpp>
#include <snek3d/StaticObject.hpp>
#include <snek3d/InputMap.hpp>
#include <snek3d/util.hpp>

int main() {
    InitWindow(800, 600, "Skibidi");
    SetTargetFPS(60);
    DisableCursor();
    Snek3D::Player chick("chick.glb");
    Snek3D::StaticObject apple("apple.glb");
    Model terrain = Snek3D::procedure_terrain();
    Texture2D grass = LoadTexture("grass.png");
    terrain.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = grass;
    chick.scale = 3;
    apple.scale = 5;
    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        chick.begin_perspective();
        DrawGrid(10, 1);
        chick.draw();
        apple.draw();
        DrawModel(terrain, {0,-3,0}, 1, WHITE);
        chick.end_perspective();
        EndDrawing();
    }
    CloseWindow();
}
