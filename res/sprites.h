#ifndef SPRITES_H_INCLUDED
#define SPRITES_H_INCLUDED

#include <utility>
#include <string>
#include <map>

#include "../graphics/spriteDefinition.h"

using namespace Graphics;

namespace Resources {
    class SpriteIndex {
        public:
            static const std::map<std::string, std::pair<int, int>> SheetDimensions;
            static SpriteDefinition KID_NORTH_0;
            static SpriteDefinition KID_NORTH_1;
            static SpriteDefinition KID_NORTH_2;
            static SpriteDefinition KID_SOUTH_0;
            static SpriteDefinition KID_SOUTH_1;
            static SpriteDefinition KID_SOUTH_2;
            static SpriteDefinition KID_EAST_0;
            static SpriteDefinition KID_EAST_1;
            static SpriteDefinition KID_EAST_2;
            static SpriteDefinition KID_WEST_0;
            static SpriteDefinition KID_WEST_1;
            static SpriteDefinition KID_WEST_2;

            static SpriteDefinition TEEN_NORTH_0;
            static SpriteDefinition TEEN_NORTH_1;
            static SpriteDefinition TEEN_NORTH_2;
            static SpriteDefinition TEEN_SOUTH_0;
            static SpriteDefinition TEEN_SOUTH_1;
            static SpriteDefinition TEEN_SOUTH_2;
            static SpriteDefinition TEEN_EAST_0;
            static SpriteDefinition TEEN_EAST_1;
            static SpriteDefinition TEEN_EAST_2;
            static SpriteDefinition TEEN_WEST_0;
            static SpriteDefinition TEEN_WEST_1;
            static SpriteDefinition TEEN_WEST_2;

            static SpriteDefinition MUM_NORTH_0;
            static SpriteDefinition MUM_NORTH_1;
            static SpriteDefinition MUM_NORTH_2;
            static SpriteDefinition MUM_SOUTH_0;
            static SpriteDefinition MUM_SOUTH_1;
            static SpriteDefinition MUM_SOUTH_2;
            static SpriteDefinition MUM_EAST_0;
            static SpriteDefinition MUM_EAST_1;
            static SpriteDefinition MUM_EAST_2;
            static SpriteDefinition MUM_WEST_0;
            static SpriteDefinition MUM_WEST_1;
            static SpriteDefinition MUM_WEST_2;
    };
}

#endif