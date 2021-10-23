#include "mapObject.h"
#include "../res/sprites.h"
#include <iostream>

namespace Play {
    using std::string;
    using std::map;
    using Graphics::Animation;
    using Graphics::EasingType;
    using Graphics::Frame;
    using Graphics::SpriteDefinition;
    using Resources::AnimationIndex;
    using Resources::AnimationTrigger;
    using Resources::MapObjectTemplate;
    using Resources::SpriteIndex;
    using Util::Location;

    map<Direction, AnimationTrigger> _directionTriggers = {
        { Direction::NORTH, AnimationTrigger::NORTH_MOVE },
        { Direction::SOUTH, AnimationTrigger::SOUTH_MOVE },
        { Direction::EAST, AnimationTrigger::EAST_MOVE },
        { Direction::WEST, AnimationTrigger::WEST_MOVE }
    };

    // LIFECYCLE

    /**
     * Constructor
     */
    MapObject::MapObject(const MapObjectTemplate& tmpl) {
        _isDense = tmpl.IsDense;
        _imageFileName = tmpl.ImagePath;
        _onInspect = tmpl.OnInspect;

        _animations = {};

        for(auto& entry : tmpl.Animations) {
            _animations.insert({ entry.first, new Animation(entry.second.first, entry.second.second) });
        }

        // If there's nothing for IDLE, put in a place holder so we don't explode.
        if (_animations.count(AnimationTrigger::IDLE) <= 0) {
            _animations.insert({ AnimationTrigger::IDLE, new Animation(AnimationIndex::DEFAULT, EasingType::LINEAR) });
        }

        triggerAnimation(AnimationTrigger::IDLE, 0);
    }

    /**
     * Destructor
     */
    MapObject::~MapObject() {
        for(auto& entry : _animations) {
            // hrmmmmmmmmm
            // This throws when MapCells are instantiated :/  what...
            //deletePtr(entry.second);
        }

        _animations.empty();
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
    string MapObject::imageFileName(void) const { return _imageFileName; }
    string MapObject::imageFileName(const string& name) {
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
        if (_facing != facing_) {
            _facing = facing_;

            triggerAnimation(_directionTriggers[_facing], WALK_TIME);
        }
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

    // METHODS

    /**
     * When an animation trigger is pulled, kick off any relevant animation.
     */
    void MapObject::triggerAnimation(AnimationTrigger event, int animationDuration) {
        if (_animations.count(event) > 0) {
            _activeAnimation = _animations.at(event);
        }

        _activeAnimation->start(animationDuration);
    }

    /**
     * The sprite used to represent this mob at the current point in time.
     */
    const SpriteDefinition* MapObject::currentSprite() const {
        return _activeAnimation->getFrame();
    }
}