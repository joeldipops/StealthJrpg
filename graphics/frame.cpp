#include "frame.h"

namespace Graphics {

    // LIFECYCLE

    /**
     * Constructor
     */
    Frame::Frame(SpriteDefinition* image, int x, int y)
    : SpriteDefinition(image->sheet(), image->index()) {
        _xOffset = x;
        _yOffset = y;
    }
}