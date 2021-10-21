#include "spriteDefinition.h"

namespace Graphics {
    using namespace std;

    /**
     * Constructor
     */
    SpriteDefinition::SpriteDefinition(string sheet, int index) {
        _sheet = sheet;
        _index = index;
    }

    /**
     *
     */
    const string SpriteDefinition::sheet() const {
        return _sheet;
    }

    /**
     * 
     */
    const int SpriteDefinition::index() const {
        return _index;
    }
}