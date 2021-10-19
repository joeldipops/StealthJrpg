#include "spriteDefinition.h"

using namespace Graphics;

/**
 * Constructor
 */
SpriteDefinition::SpriteDefinition(std::string sheet, int index) {
    _sheet = sheet;
    _index = index;
}

/**
 *
 */
const std::string SpriteDefinition::sheet() const {
    return _sheet;
}

/**
 * 
 */
const int SpriteDefinition::index() const {
    return _index;
}