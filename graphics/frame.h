#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <vector>
#include <ctime>

#include "../graphics/sprite.h"

namespace Graphics {

    /**
     * A frame of animation.
     */
    class Frame : public Sprite {
        public:
            Frame(Sprite* image, int x = 0, int y = 0);
        private:
            int _xOffset;
            int _yOffset;
    };
}

#endif