#include "raylib/raylib.h"
#include <snek3d/Texture.hpp>


void Snek3D::Texture::set_filter(TextureFilter filter) {
    SetTextureFilter(tex, filter);
}

void Snek3D::Texture::set_wrap(TextureWrap wrap) {
    SetTextureWrap(tex, wrap);
}
