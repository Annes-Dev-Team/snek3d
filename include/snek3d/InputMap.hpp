#include <vector>

namespace Snek3D {
    struct InputMap {
        std::vector<int> keys;

        bool is_pressed();
        bool is_down();
        bool is_pressed_twice();
    };
}
