#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <vector>
#include <ctime>

#include "../res/sprites.h"

namespace Graphics {

    /**
     * A frame of animation.
     */
    class Frame : public SpriteDefinition {
        public:
            Frame(SpriteDefinition* image, int x = 0, int y = 0);
        private:
            int _xOffset;
            int _yOffset;
    };
}

#endif