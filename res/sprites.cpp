#include <map>
#include "sprites.h"

using namespace Resources;

Sprite::Sprite(SDL_Texture* texture, int x, int y, int width, int height) {
    _texture = texture;
    _stencil.x = x;
    _stencil.y = y;
    _stencil.w = width;
    _stencil.h = height;
}

Sprite::Sprite(SDL_Texture* texture, SDL_Rect* stencil) {
    _texture = texture;
    _stencil.x = stencil->x;
    _stencil.y = stencil->y;
    _stencil.w = stencil->w;
    _stencil.h = stencil->h;
}

SDL_Texture* Sprite::texture() {
    return _texture;
}

SDL_Rect Sprite::stencil() {
    return _stencil;
}

/**
 * Constructor
 */
SpriteDefinition::SpriteDefinition(std::string sheet, int index) {
    _sheet = sheet;
    _index = index;
}

std::string SpriteDefinition::sheet() {
    return _sheet;
}

int SpriteDefinition::index() {
    return _index;
}

const std::string PC_SPRITE_FILE = "images/AH_SpriteSheet_People1.png";
const std::string PC_SPRITE_FILE_2 = "images/AH_SpriteSheet_People2.png";

const std::map<std::string, std::pair<int, int>> SpriteIndex::SheetDimensions = {
    { PC_SPRITE_FILE, { 12, 8 } },
    { PC_SPRITE_FILE_2, { 12, 8 } }
};

SpriteDefinition SpriteIndex::KID_SOUTH_0 = SpriteDefinition(PC_SPRITE_FILE, 52);
SpriteDefinition SpriteIndex::KID_SOUTH_1 = SpriteDefinition(PC_SPRITE_FILE, 51);
SpriteDefinition SpriteIndex::KID_SOUTH_2 = SpriteDefinition(PC_SPRITE_FILE, 53);

SpriteDefinition SpriteIndex::KID_WEST_0 = SpriteDefinition(PC_SPRITE_FILE, 63);
SpriteDefinition SpriteIndex::KID_WEST_1 = SpriteDefinition(PC_SPRITE_FILE, 62);
SpriteDefinition SpriteIndex::KID_WEST_2 = SpriteDefinition(PC_SPRITE_FILE, 64);

SpriteDefinition SpriteIndex::KID_EAST_0 = SpriteDefinition(PC_SPRITE_FILE, 75);
SpriteDefinition SpriteIndex::KID_EAST_1 = SpriteDefinition(PC_SPRITE_FILE, 74);
SpriteDefinition SpriteIndex::KID_EAST_2 = SpriteDefinition(PC_SPRITE_FILE, 76);

SpriteDefinition SpriteIndex::KID_NORTH_0 = SpriteDefinition(PC_SPRITE_FILE, 87);
SpriteDefinition SpriteIndex::KID_NORTH_1 = SpriteDefinition(PC_SPRITE_FILE, 86);
SpriteDefinition SpriteIndex::KID_NORTH_2 = SpriteDefinition(PC_SPRITE_FILE, 88);

SpriteDefinition SpriteIndex::TEEN_NORTH_0 = SpriteDefinition(PC_SPRITE_FILE, 84);
SpriteDefinition SpriteIndex::TEEN_NORTH_1 = SpriteDefinition(PC_SPRITE_FILE, 83);
SpriteDefinition SpriteIndex::TEEN_NORTH_2 = SpriteDefinition(PC_SPRITE_FILE, 85);

SpriteDefinition SpriteIndex::TEEN_SOUTH_0 = SpriteDefinition(PC_SPRITE_FILE, 49);
SpriteDefinition SpriteIndex::TEEN_SOUTH_1 = SpriteDefinition(PC_SPRITE_FILE, 48);
SpriteDefinition SpriteIndex::TEEN_SOUTH_2 = SpriteDefinition(PC_SPRITE_FILE, 50);

SpriteDefinition SpriteIndex::TEEN_WEST_0 = SpriteDefinition(PC_SPRITE_FILE, 60);
SpriteDefinition SpriteIndex::TEEN_WEST_1 = SpriteDefinition(PC_SPRITE_FILE, 59);
SpriteDefinition SpriteIndex::TEEN_WEST_2 = SpriteDefinition(PC_SPRITE_FILE, 61);

SpriteDefinition SpriteIndex::TEEN_EAST_0 = SpriteDefinition(PC_SPRITE_FILE, 72);
SpriteDefinition SpriteIndex::TEEN_EAST_1 = SpriteDefinition(PC_SPRITE_FILE, 71);
SpriteDefinition SpriteIndex::TEEN_EAST_2 = SpriteDefinition(PC_SPRITE_FILE, 73);

SpriteDefinition SpriteIndex::MUM_SOUTH_0 = SpriteDefinition(PC_SPRITE_FILE_2, 1);
SpriteDefinition SpriteIndex::MUM_SOUTH_1 = SpriteDefinition(PC_SPRITE_FILE_2, 2);
SpriteDefinition SpriteIndex::MUM_SOUTH_2 = SpriteDefinition(PC_SPRITE_FILE_2, 3);

SpriteDefinition SpriteIndex::MUM_WEST_0 = SpriteDefinition(PC_SPRITE_FILE_2, 13);
SpriteDefinition SpriteIndex::MUM_WEST_1 = SpriteDefinition(PC_SPRITE_FILE_2, 14);
SpriteDefinition SpriteIndex::MUM_WEST_2 = SpriteDefinition(PC_SPRITE_FILE_2, 15);

SpriteDefinition SpriteIndex::MUM_EAST_0 = SpriteDefinition(PC_SPRITE_FILE_2, 25);
SpriteDefinition SpriteIndex::MUM_EAST_1 = SpriteDefinition(PC_SPRITE_FILE_2, 26);
SpriteDefinition SpriteIndex::MUM_EAST_2 = SpriteDefinition(PC_SPRITE_FILE_2, 27);

SpriteDefinition SpriteIndex::MUM_NORTH_0 = SpriteDefinition(PC_SPRITE_FILE_2, 37);
SpriteDefinition SpriteIndex::MUM_NORTH_1 = SpriteDefinition(PC_SPRITE_FILE_2, 38);
SpriteDefinition SpriteIndex::MUM_NORTH_2 = SpriteDefinition(PC_SPRITE_FILE_2, 39);
