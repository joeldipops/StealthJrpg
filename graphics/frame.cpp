#include "frame.h"

namespace Graphics {

    // LIFECYCLE

    /**
     * Constructor
     */
    Frame::Frame(Sprite* image, int x, int y)
     : Sprite(image->texture(), image->stencil()) {
        _xOffset = x;
        _yOffset = y;
    }
}