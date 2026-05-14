#include "snek3d/InputMap.hpp"
#include "raylib/raylib.h"

bool Snek3D::InputMap::is_down() {
    for (int i : keys) {
        if (IsKeyDown(i)) {
            return true;
        }
    }
    return false;
}

bool Snek3D::InputMap::is_pressed() {
    for (int i : keys) {
        if (IsKeyPressed(i)) {
            return true;
        }
    }
    return false;
}

bool Snek3D::InputMap::is_pressed_twice() {
    for (int i : keys) {
        if (IsKeyPressedRepeat(i)) {
            return true;
        }
    }
    return false;
}
