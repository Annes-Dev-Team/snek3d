#include "snek3d/CharacterModel2D.hpp"
#include <raylib/physac.h>
namespace Snek3D {
    struct Player2D {
        CharacterModel2D model;
        // for top down games
        bool top = true;
        bool is_moving = 0;
        float x;
        float y;
        float scale;
        float rot;
        Color tint;
        PhysicsBody body;
        
        Player2D(const std::string& path, float xpos=0, float ypos=0, float scalee=1, Color tintt=WHITE, bool topdown=true);
        void update(float fps=12, float speed=5);
        void draw();
    };
}
