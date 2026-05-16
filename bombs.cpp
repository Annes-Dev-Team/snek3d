#include "include/raylib/raylib.h"
#include "raylib/raylib.h"
#include "raylib/raymath.h"
#include "snek3d/CharacterModel.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <snek3d/MapPresets.hpp>
#include <snek3d/StaticObject.hpp>
#include <snek3d/util.hpp>
#include <thread>
#include <vector>
#define BOMBSIZE 0.274365 
struct Bomb {
    Snek3D::StaticObject obj;
    BoundingBox box;
    void update() {
        box = Snek3D::make_bounding_box(obj.x - BOMBSIZE/2, obj.y-BOMBSIZE/2, obj.z-BOMBSIZE/2, BOMBSIZE, BOMBSIZE, BOMBSIZE);
    }
    void draw() {
        obj.draw();
        DrawBoundingBox(box, RED);
    }
};

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
    BoundingBox chickbox;
    Model bombmodel = LoadModel("assets/bomb.glb");
    Sound bombsound = LoadSound("assets/bomb.mp3");
    std::vector<Bomb> bombs = {};
    bombs.push_back({{&bombmodel, 0, 5}});
    float x = 0;
    int score = 0;
    int randnum;
    srand(time(0));

    while (!WindowShouldClose()) {
        if (Snek3D::MOVE_LEFT_PRESET.is_down()) {
            x += 0.05;
        }
        if (Snek3D::MOVE_RIGHT_PRESET.is_down()) {
            x -= 0.05;
        }
        x= Clamp(x, -1.5, 1.5);
        randnum = GetRandomValue(0, 40);
        if (randnum == 0) {
            bombs.push_back(
                {{&bombmodel, Snek3D::get_random_float(-2, 2), 3, 0, 2}}
            );
        }
        player.current_animation = player.walkanim;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.update();


        chickbox = Snek3D::make_bounding_box(
            x - 0.2,-1,-0.2, 0.4, 0.4, 0.4
        );
        BeginMode3D(camera);
        for (size_t i = 0; i < bombs.size(); ) {
            bombs[i].update();
            bombs[i].obj.y -= 0.05f;
            bombs[i].draw();

            if (CheckCollisionBoxes(chickbox, bombs[i].box)) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                return 0;
            }

            if (bombs[i].obj.y < -3) {
                bombs.erase(bombs.begin() + i);
                PlaySound(bombsound);
                score++;
            } else {
                i++;
            }
        }
        player.draw(x, -1);
        DrawBoundingBox(chickbox, BLUE);
        EndMode3D();
        DrawText(
            TextFormat("Score: %i", score), 0, 0, 20, BLACK
        );
        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
