#include <map>
#include "sprites.h"

using namespace Resources;

/**
 * Constructor
 */
Sprite::Sprite(std::string sheet, int index) {
    _sheet = sheet;
    _index = index;
}

std::string Sprite::Sheet() {
    return _sheet;
}

int Sprite::Index() {
    return _index;
}

const std::string PC_SPRITE_FILE = "images/AH_SpriteSHeet_People1.png";

const std::map<std::string, int> SpriteIndex::SheetWidths = {
    { PC_SPRITE_FILE, 12 }
};

const Sprite SpriteIndex::KID_SOUTH_0 = Sprite(PC_SPRITE_FILE, 52);
const Sprite SpriteIndex::KID_SOUTH_1 = Sprite(PC_SPRITE_FILE, 51);
const Sprite SpriteIndex::KID_SOUTH_2 = Sprite(PC_SPRITE_FILE, 53);

const Sprite SpriteIndex::KID_WEST_0 = Sprite(PC_SPRITE_FILE, 63);
const Sprite SpriteIndex::KID_WEST_1 = Sprite(PC_SPRITE_FILE, 62);
const Sprite SpriteIndex::KID_WEST_2 = Sprite(PC_SPRITE_FILE, 64);

const Sprite SpriteIndex::KID_EAST_0 = Sprite(PC_SPRITE_FILE, 75);
const Sprite SpriteIndex::KID_EAST_1 = Sprite(PC_SPRITE_FILE, 74);
const Sprite SpriteIndex::KID_EAST_2 = Sprite(PC_SPRITE_FILE, 76);

const Sprite SpriteIndex::KID_NORTH_0 = Sprite(PC_SPRITE_FILE, 87);
const Sprite SpriteIndex::KID_NORTH_1 = Sprite(PC_SPRITE_FILE, 86);
const Sprite SpriteIndex::KID_NORTH_2 = Sprite(PC_SPRITE_FILE, 88);
