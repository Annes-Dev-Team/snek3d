#include "include/raylib/raylib.h"
#include "raylib/raylib.h"
#include "snek3d/CharacterModel.hpp"
#include <cstdlib>
#include <ctime>
#include <snek3d/MapPresets.hpp>
#include <snek3d/StaticObject.hpp>
#include <vector>

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
    InitAudioDevice();
    SetTargetFPS(60);
    Snek3D::CharacterModel player("assets/chick.glb");
    Model bombmodel = LoadModel("assets/bomb.glb");
    Sound bombsound = LoadSound("assets/bomb.mp3");
    std::vector<Snek3D::StaticObject> bombs = {};
    bombs.push_back(Snek3D::StaticObject(&bombmodel, 0, 5));
    float x = 0;
    int randnum;
    srand(time(0));
    
    while (!WindowShouldClose()) {
        if (Snek3D::MOVE_LEFT_PRESET.is_down()) {
            x += 0.05;
        }
        if (Snek3D::MOVE_RIGHT_PRESET.is_down()) {
            x -= 0.05;
        }
        randnum = GetRandomValue(0, 40);
        if (randnum == 0) {
            bombs.push_back(
                Snek3D::StaticObject(&bombmodel, -2 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (2 - -2))), 3, 0, 2)
            );
        }
        player.current_animation = player.walkanim;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.update();
        BeginMode3D(camera);
        for (size_t i = 0; i < bombs.size(); ) {
            bombs[i].y -= 0.05f;
            bombs[i].draw();

            if (bombs[i].y < -3) {
                bombs.erase(bombs.begin() + i);
                PlaySound(bombsound);
            } else {
                i++;
            }
        }
        player.draw(x, -1);
        EndMode3D();
        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();
}
