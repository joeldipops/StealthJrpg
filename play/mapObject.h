#ifndef MAPOBJECT_H_INCLUDED
#define MAPOBJECT_H_INCLUDED

#include <string>

#include "../globalConstants.h"
#include "../util/utils.h"
#include "../res/sprites.h"
#include "../res/templates.h"
#include "../util/events.h"
#include "../graphics/frame.h"
#include "../graphics/animation.h"

using namespace Util;
using namespace Resources;
using namespace Graphics;

namespace Play {
    enum AnimationTrigger {
        IDLE,
        NORTH_MOVE,
        SOUTH_MOVE,
        EAST_MOVE,
        WEST_MOVE
    };

    struct PlayStateContainer;
    typedef PlayStateContainer& (*PlayEventHandler)(MapObject*, PlayStateContainer&);
    class MapObject {
        public:
            MapObject(const MapObjectTemplate&);
            virtual ~MapObject(void) {};
            bool isDense(void);
            void setUpSprite(Direction, SpriteDefinition* def);
            void setUpSprite(SpriteDefinition* def);
            void setUpAnimation(AnimationTrigger, Animation*);
            virtual const SpriteDefinition* currentSprite(void) const;
            std::string imageFileName(const std::string&);
            std::string imageFileName(void) const;

            virtual PlayStateContainer& onInspect(PlayStateContainer&) = 0;

            Location location(int, int);
            Location location(const Location*);

            virtual Direction facing(void) const;
            virtual Direction facing(Direction);

            virtual int x(int);
            virtual int x(void) const;
            virtual int y(int);
            virtual int y(void) const;
            virtual bool isMob(void) const { return false; };
            virtual bool isPlayerParty(void) const {return false;};

        protected:
            bool isDense(bool);

            const Handler<MapObject, PlayStateContainer> onInspectFn(void) const;
        private:
            bool _isDense;
            std::string _imageFileName;
            std::map<Direction, SpriteDefinition*> _sprites;
            int _x = 0;
            int _y = 0;
            Direction _facing = Direction::NONE;
            Handler<MapObject, PlayStateContainer> _onInspect;
    };
}

#endif
