#include "snek3d/MapPresets.hpp"
#include "raylib/raylib.h"

namespace Snek3D {
    InputMap MOVE_DOWN_PRESET = {
        {{EVENT_KEY, KEY_S},{EVENT_KEY, KEY_DOWN}}
    };
    InputMap MOVE_UP_PRESET = {
        {{EVENT_KEY, KEY_W},{EVENT_KEY, KEY_UP}}
    };
    InputMap MOVE_LEFT_PRESET = {
        {{EVENT_KEY, KEY_A},{EVENT_KEY, KEY_LEFT}}
    };
    InputMap MOVE_RIGHT_PRESET = {
        {{EVENT_KEY, KEY_D},{EVENT_KEY, KEY_RIGHT}}
    };

    InputMap EAT_PRESET = {
        {{EVENT_KEY, KEY_E}}
    };
    InputMap FIGHT_PRESET = {
        {{EVENT_KEY, KEY_F},{EVENT_MOUSE, MOUSE_BUTTON_LEFT}}
    };
    InputMap JUMP_PRESET = {
        {{EVENT_KEY, KEY_SPACE}}
    };
    
}
