#ifndef ANIMATIONS_H_INCLUDED
#define ANIMATIONS_H_INCLUDED

#include <utility>
#include <string>
#include <map>

#include "../graphics/animation.h"

using namespace Graphics;

namespace Resources {
    class AnimationIndex {
        public:
            static std::vector<Frame*> KID_NORTH;
            static std::vector<Frame*> KID_SOUTH;
            static std::vector<Frame*> KID_EAST;
            static std::vector<Frame*> KID_WEST;
    };
}

#endif