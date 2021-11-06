#ifndef ANIMATIONS_H_INCLUDED
#define ANIMATIONS_H_INCLUDED

#include <utility>
#include <string>
#include <map>

#include "../graphics/animation.h"

namespace Resources {
    enum AnimationTrigger {
        IDLE,
        NORTH_MOVE,
        SOUTH_MOVE,
        EAST_MOVE,
        WEST_MOVE
    };

    class AnimationIndex {
        public:
            static std::vector<Graphics::SpriteDefinition*> DEFAULT;
            static std::vector<Graphics::SpriteDefinition*> KID_NORTH;
            static std::vector<Graphics::SpriteDefinition*> KID_SOUTH;
            static std::vector<Graphics::SpriteDefinition*> KID_EAST;
            static std::vector<Graphics::SpriteDefinition*> KID_WEST;
    };
}

#endif