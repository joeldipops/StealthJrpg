#include "mapObject.h"
#include "../res/sprites.h"

using namespace Play;
using namespace Graphics;
using namespace Resources;

// LIFECYCLE

/**
 * Constructor
 */
MapObject::MapObject(const MapObjectTemplate& tmpl) {
    _isDense = tmpl.IsDense;
    _imageFileName = tmpl.ImagePath;
    _onInspect = tmpl.OnInspect;

    if (tmpl.SpriteDef != NULL) {
        setUpSprite(tmpl.SpriteDef);
    } else {
        // Ensure each direction has an entry.
        setUpSprite(NULL);

        // If nothing specified for NONE, have it match SOUTH.
        if (tmpl.SpriteMap.count(Direction::NONE) > 0 && tmpl.SpriteMap.at(Direction::NONE) != NULL) {
            setUpSprite(Direction::NONE, tmpl.SpriteMap.at(Direction::SOUTH));
        } else if (tmpl.SpriteMap.count(Direction::SOUTH) > 0 && tmpl.SpriteMap.at(Direction::SOUTH) != NULL) {
            setUpSprite(Direction::NONE, tmpl.SpriteMap.at(Direction::SOUTH));
        }

        if (tmpl.SpriteMap.count(Direction::NORTH) > 0 && tmpl.SpriteMap.at(Direction::NORTH) != NULL) {
            setUpSprite(Direction::NORTH, tmpl.SpriteMap.at(Direction::NORTH));
        }
        if (tmpl.SpriteMap.count(Direction::SOUTH) > 0 && tmpl.SpriteMap.at(Direction::SOUTH) != NULL) {
            setUpSprite(Direction::SOUTH, tmpl.SpriteMap.at(Direction::SOUTH));
        }
        if (tmpl.SpriteMap.count(Direction::EAST) > 0 && tmpl.SpriteMap.at(Direction::EAST) != NULL) {
            setUpSprite(Direction::EAST, tmpl.SpriteMap.at(Direction::EAST));
        }
        if (tmpl.SpriteMap.count(Direction::WEST) > 0 && tmpl.SpriteMap.at(Direction::WEST) != NULL) {
            setUpSprite(Direction::WEST, tmpl.SpriteMap.at(Direction::WEST));
        }
    }
}

/**
 * Function trigged when object is inspected by player.
 */
const Handler<MapObject, PlayStateContainer> MapObject::onInspectFn(void) const { return _onInspect; }

// PROPERTIES

/**
 * Sets and gets the path to this object's image.
 * @param name The filename.
 * @return the filename
 */
std::string MapObject::imageFileName(void) const { return _imageFileName; }
std::string MapObject::imageFileName(const std::string& name) {
    _imageFileName = name;
    return _imageFileName;
}

/**
 * Gets or sets the Mob's X position.
 * @param x The horizontal co-ordinate of the map
 * @return
 */
int MapObject::x(void) const { return _x; }
int MapObject::x(int x_) {
    _x = x_;
    return x();
}

/**
 * Gets or sets the Mob's Y position.
 * @param y The vertical co-ordinate on the map
 * @return
 */
int MapObject::y(void) const { return _y; }
int MapObject::y(int y_) {
    _y = y_;
    return y();
}

/**
 * Sets and gets whether this object can be walked through.
 * @param The density.
 * @return The density.
 */
bool MapObject::isDense(void) { return _isDense; }
bool MapObject::isDense(bool isDense_) {
    _isDense = isDense_;
    return _isDense;
}

/**
 * Gets or sets the direction the mob is facing.
 */
Direction MapObject::facing(void) const { return _facing; }
Direction MapObject::facing(Direction facing_) {
    _facing = facing_;
    return _facing;
}

// METHODS

/**
 * Gets or sets the X/Y coordinates of the mob.
 * @param x
 * @param y
 * @return
 */
Location MapObject::location(int x_, int y_) {
    x(x_);
    y(y_);
    return Location(x_, y_);
}

/**
 * Gets or sets the X/Y coordinates of the mob.
 * @param loc
 * @return
 */
Location MapObject::location(const Location* loc) {
    if (loc != nullptr) {
        x(loc->X);
        y(loc->Y);
    }
    return Location(&_x, &_y);
}

/**
 * The sprite used to represent this mob at the current point in time.
 */
const SpriteDefinition* MapObject::currentSprite() const {
    if (_sprites.count(_facing) > 0) {
        return _sprites.at(_facing); 
    } else {
        return NULL;
    }
}

/**
 * Set object up to be represented by a single image.
 * @param def The image definition.
 */
void MapObject::setUpSprite(SpriteDefinition* def) {
    _sprites[Direction::NONE] = def;
    _sprites[Direction::NORTH] = def;
    _sprites[Direction::SOUTH] = def;
    _sprites[Direction::EAST] = def;
    _sprites[Direction::WEST] = def;
}

/**
 * Set object to be represented by different images depending on the facing direction.
 * @param dir The facing direction this image will represent.
 * @param def The image definition.
 */
void MapObject::setUpSprite(Direction dir, SpriteDefinition* def) {
    _sprites[dir] = def;
}
