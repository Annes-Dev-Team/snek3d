#include <vector>

namespace Snek3D {
    enum InputEvents {
        EVENT_KEY,
        EVENT_MOUSE,
        EVENT_GAMEPAD
    };

    struct InputEvent {
        InputEvents type;
        int value;
        
        bool is_pressed();
        bool is_down();
    };

    struct InputMap {
        std::vector<InputEvent> events = {};

        bool is_pressed();
        bool is_down();
    };
}
