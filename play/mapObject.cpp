#include <iostream>

#include "mapObject.h"
#include "../res/sprites.h"
#include "../util/assetCache.h"

namespace Play {
    using std::string;
    using std::map;
    using std::vector;

    using Graphics::Animation;
    using Graphics::EasingType;
    using Graphics::Frame;
    using Graphics::SpriteDefinition;
    using Resources::AnimationIndex;
    using Resources::AnimationTrigger;
    using Resources::MapObjectTemplate;
    using Resources::SpriteIndex;
    using Util::AssetCache;
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
    MapObject::MapObject(const MapObjectTemplate& tmpl, AssetCache* cache) {
        _isDense = tmpl.IsDense;
        _onInspect = tmpl.OnInspect;

        _animations = {};

        if (cache != NULL) {
            for(auto& entry : tmpl.Animations) {
                vector<Frame> frames;
                for(auto& def : entry.second.first) {
                    frames.push_back(Frame(cache->getSprite(def)));
                }

                _animations.insert({ entry.first, new Animation(frames, entry.second.second) });
            }

            // If there's nothing for IDLE, put in a placeholder so we don't explode.
            if (_animations.count(AnimationTrigger::IDLE) <= 0) {
                if (tmpl.ImagePath.length() > 0) {
                    _animations.insert({ AnimationTrigger::IDLE, new Animation({ Frame(cache->getSprite(tmpl.ImagePath)) }, EasingType::LINEAR) });

                } else {
                    vector<Frame> frames;
                    for(auto& entry : AnimationIndex::DEFAULT) {
                        frames.push_back(Frame(cache->getSprite(entry)));
                    }
                    _animations.insert({ AnimationTrigger::IDLE, new Animation(frames, EasingType::LINEAR) });
                }
            }
        }

        triggerAnimation(AnimationTrigger::IDLE, 0);
    }

    /**
     * Overload copy to allow animations to be deleted in Destructor.
     */
    MapObject::MapObject(const MapObject& that) {
        _facing = that._facing;
        _isDense = that._isDense;
        _onInspect = that._onInspect;
        _x = that._x;
        _y = that._y;

        _animations = {};

        for(auto& entry : that._animations) {
            if (_activeAnimation == entry.second) {
                _activeAnimation = new Animation(*entry.second);
                _animations.insert({ entry.first, _activeAnimation });
            } else {
                _animations.insert({ entry.first, new Animation(*entry.second) });
            }
        }
    }

    /**
     * Overload copy to allow animations to be deleted in Destructor.
     */
    MapObject& MapObject::operator=(const MapObject& that) {
        this->_facing = that._facing;
        this->_isDense = that._isDense;
        this->_onInspect = that._onInspect;
        this->_x = that._x;
        this->_y = that._y;

        _animations = {};

        for(auto& entry : that._animations) {
            if (this->_activeAnimation == entry.second) {
                this->_activeAnimation = new Animation(*entry.second);
                _animations.insert({ entry.first, this->_activeAnimation });
            } else {
                _animations.insert({ entry.first, new Animation(*entry.second) });
            }
        }

        return *this;
    }

    /**
     * Destructor
     */
    MapObject::~MapObject() {
        for(auto& entry : _animations) {
            deletePtr(entry.second);
        }

        _animations.empty();
    }

    PlayStateContainer& MapObject::onInspect(PlayStateContainer& container) {
        return container;
    }

    /**
     * Function trigged when object is inspected by player.
     */
    const Handler<MapObject, PlayStateContainer> MapObject::onInspectFn(void) const { return _onInspect; }

    // PROPERTIES

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
        }
        triggerAnimation(_directionTriggers[_facing], WALK_TIME);        
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

        if (_activeAnimation != NULL) {
            _activeAnimation->start(animationDuration);
        }
    }

    /**
     * The sprite used to represent this mob at the current point in time.
     */
    const Frame* MapObject::currentSprite() const {
        if (_activeAnimation != NULL) {
            return _activeAnimation->getFrame();
        } else {
            return _animations.at(AnimationTrigger::IDLE)->getFrame();
        }

    }
}