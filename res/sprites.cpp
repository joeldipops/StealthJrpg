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

const std::map<std::string, std::pair<int, int>> SpriteIndex::SheetDimensions = {
    { PC_SPRITE_FILE, { 12, 8 } }
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
