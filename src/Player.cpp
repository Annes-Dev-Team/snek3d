#include "snek3d/Player.hpp"
#include <snek3d/util.hpp>
#include "raylib/raylib.h"
#include <raylib/raymath.h>
#include "snek3d/CharacterModel.hpp"

Snek3D::Player::Player(
    const std::string path,
    float xpos,
    float ypos,
    float zpos,
    float scalee,
    Color tintt,
    Vector3 headoffset
)
    : cmodel(path),
      x(xpos),
      y(ypos),
      z(zpos),
      scale(scalee),
      tint(tintt),
      head_offset(headoffset)
{
}

void Snek3D::Player::begin_perspective(bool flip) {
    Vector3 oldpos = {x,y,z};
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    
    x = camera.position.x - head_offset.x;
    y = camera.position.y - head_offset.y;
    z = camera.position.z - head_offset.z;
    is_moving = !Vector3Equals(oldpos, {x,y,z});
    if (is_moving) {
        cmodel.current_animation = cmodel.walkanim;
    }
    else {
        cmodel.current_animation = cmodel.idleanim;
    }
    rot = get_camera_yaw(&camera) + ((flip) ? 180: 0);
    
    //std::cout << camera.position.x << " "
    //      << camera.position.y << " "
    //      << camera.position.z << std::endl;
    cmodel.update();
    BeginMode3D(camera);
}

void Snek3D::Player::end_perspective() {
    EndMode3D();
}

void Snek3D::Player::draw() {
    cmodel.draw_advanced(x, y, z, {0,1,0}, rot, {scale, scale, scale}, tint);
}
