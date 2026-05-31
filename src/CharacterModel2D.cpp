#include <filesystem>
#include <iostream>

#include <raylib/raylib.h>

#include <snek3d/CharacterModel2D.hpp>

namespace fs = std::filesystem;

std::vector<Texture2D*>*
Snek3D::CharacterModel2D::find_animation(
    const std::string& name)
{
    for (auto& anim : animations)
    {
        if (anim.name == name)
            return &anim.frames;
    }

    return nullptr;
}

void Snek3D::CharacterModel2D::load_animations(
    const std::string& path)
{
    animations.clear();

    if (!fs::exists(path))
        return;

    for (const auto& entry : fs::directory_iterator(path))
    {
        if (!entry.is_directory())
            continue;

        Animation anim;
        anim.name = entry.path().filename().string();

        for (const auto& frame : fs::directory_iterator(entry.path()))
        {
            if (!frame.is_regular_file())
                continue;

            std::string ext =
                frame.path().extension().string();

            if (
                ext == ".png" ||
                ext == ".jpg" ||
                ext == ".jpeg" ||
                ext == ".bmp")
            {
                Texture2D* tex =
                    new Texture2D(
                        LoadTexture(
                            frame.path()
                                .string()
                                .c_str()));

                anim.frames.push_back(tex);
            }
        }

        animations.push_back(anim);
    }

    walkanim  = find_animation("walk");
    runanim   = find_animation("run");
    idleanim  = find_animation("idle");
    sitanim   = find_animation("sit");
    swimanim  = find_animation("swim");
    climbanim = find_animation("climb");

    current_animation = idleanim;

    animframe = 0;
}

void Snek3D::CharacterModel2D::update(float fps)
{
    float delta = GetFrameTime();
    if (!current_animation)
        return;

    if (current_animation->empty())
        return;

    animation_timer += delta;

    float frame_duration = 1.0f / fps;

    while (animation_timer >= frame_duration)
    {
        animation_timer -= frame_duration;

        animframe++;

        if (animframe >= current_animation->size())
            animframe = 0;
    }
}

void Snek3D::CharacterModel2D::draw(
    float x,
    float y,
    float scale,
    Color tint)
{
    if (!current_animation)
        return;

    if (current_animation->empty())
        return;

    Texture2D* tex =
        (*current_animation)[animframe];

    DrawTextureEx(
        *tex,
        {x, y},
        0.0f,
        scale,
        tint);
}

void Snek3D::CharacterModel2D::draw_advanced(
    float x,
    float y,
    float rot,
    Vector2 scale,
    Color tint)
{
    if (!current_animation)
        return;

    if (current_animation->empty())
        return;

    Texture2D* tex =
        (*current_animation)[animframe];

    Rectangle src =
    {
        0,
        0,
        (float)tex->width,
        (float)tex->height
    };

    Rectangle dst =
    {
        x,
        y,
        tex->width * scale.x,
        tex->height * scale.y
    };

    DrawTexturePro(
        *tex,
        src,
        dst,
        {
            dst.width / 2.0f,
            dst.height / 2.0f
        },
        rot,
        tint);
}

Snek3D::CharacterModel2D::CharacterModel2D(
    const std::string& path)
{
    load_animations(path);

    std::cout
        << "New CharacterModel2D "
        << this
        << std::endl;
}

Snek3D::CharacterModel2D::CharacterModel2D()
{
    std::cout
        << "Possibly Uninitialized CharacterModel2D "
        << this
        << std::endl;
}