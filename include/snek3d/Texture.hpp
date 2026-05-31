#include "raylib/raylib.h"

namespace Snek3D {
    struct Texture {
        ::Texture tex;
        // set blurriness
        void set_filter(TextureFilter filter);
        //set is it repeating or MIRoring
        void set_wrap(TextureWrap wrap);
    };
}
