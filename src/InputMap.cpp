#include "snek3d/InputMap.hpp"
#include "raylib/raylib.h"

bool Snek3D::InputMap::is_down() {
    for (InputEvent i : events) {
        if (i.is_down()) {
            return true;
        }
    }
    return false;
}

bool Snek3D::InputMap::is_pressed() {
    for (InputEvent i : events) {
        if (i.is_pressed()) {
            return true;
        }
    }
    return false;
}

bool Snek3D::InputEvent::is_down() {
    switch (type) {
        case EVENT_KEY:
            return IsKeyDown(value);
        case EVENT_MOUSE:
            return IsMouseButtonDown(value);
        case EVENT_GAMEPAD:
            return IsGamepadButtonDown(0, value);
    }
    return false;
}

bool Snek3D::InputEvent::is_pressed() {
    switch (type) {
        case EVENT_KEY:
            return IsKeyPressed(value);
        case EVENT_MOUSE:
            return IsMouseButtonPressed(value);
        case EVENT_GAMEPAD:
            return IsGamepadButtonPressed(0, value);
    }
    return false;
}
