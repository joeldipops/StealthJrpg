#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <vector>
#include <ctime>

#include "../res/sprites.h"

using namespace Resources;

namespace Graphics {
    class Frame : SpriteDefinition {
        public:
            Frame(SpriteDefinition* image);
            Frame(SpriteDefinition* image, int x, int y);
        private:
            int _xOffset;
            int _yOffset;
    };
}

#endif