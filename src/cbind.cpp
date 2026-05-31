#include "snek3d/CharacterModel.hpp"
#include <snek3d/cbind.h>

extern "C" {
    SnekClass create_snek3d_class(SnekClassType type) {
        SnekClass ko;
        switch (type) {
            case CLASS_CHARMODEL:
                ko.data = new Snek3D::CharacterModel{};
        }
        return ko;
    }
}
