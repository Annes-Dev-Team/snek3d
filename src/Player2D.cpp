#include "raylib/raylib.h"
#include "raylib/raymath.h"
#include "snek3d/CharacterModel2D.hpp"
#include <snek3d/Player2D.hpp>
#include <snek3d/MapPresets.hpp>

void Snek3D::Player2D::draw() {
    model.draw(x,y,scale,tint);
}

void Snek3D::Player2D::update(float fps, float speed) {
    Vector2 oldpos = {x,y};
    model.update(fps);
    if (Snek3D::MOVE_DOWN_PRESET.is_down()) {
        y += speed;
    }
    if (Snek3D::MOVE_UP_PRESET.is_down()) {
        y -= speed;
    }
    if (top) {
        if (Snek3D::MOVE_LEFT_PRESET.is_down()) {
            x -= speed;
        }
        if (Snek3D::MOVE_RIGHT_PRESET.is_down()) {
            x += speed;
        }
    }

    is_moving = !Vector2Equals(oldpos, {x,y});
    Vector2 relative = Vector2Subtract({x,y}, oldpos);
    if (is_moving) {
        model.current_animation = model.walkanim;
    } else {
        model.current_animation = model.idleanim;
    }
    model.flipped = relative.x < 0;
}

Snek3D::Player2D::Player2D(const std::string& path, float xpos, float ypos, float scalee, Color tintt, bool topdown) {
    model = CharacterModel2D(path);
    x=xpos;
    y=ypos;
    scale=scalee;
    tint=tintt;
    top=topdown;
}