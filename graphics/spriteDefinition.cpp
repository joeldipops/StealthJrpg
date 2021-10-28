#include "spriteDefinition.h"

namespace Graphics {
    using std::string;

    /**
     * Constructor
     */
    SpriteDefinition::SpriteDefinition(string sheet, int index) {
        _sheet = sheet;
        _index = index;
    }

    /**
     * Filename/path of the spritesheet this sprite will be taken from.
     */
    const string SpriteDefinition::sheet() const {
        return _sheet;
    }

    /**
     * Ordinal position of the sprite from left -> right, top -> bottom.
     */
    const int SpriteDefinition::index() const {
        return _index;
    }
}