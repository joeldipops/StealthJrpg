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
#include "../util/assetCache.h"

namespace Play {
    struct PlayStateContainer;
    typedef PlayStateContainer& (*PlayEventHandler)(MapObject*, PlayStateContainer&);
    class MapObject {
        public:
            MapObject(void) {};
            MapObject(const MapObject& that);
            MapObject(const Resources::MapObjectTemplate&, Util::AssetCache*);

            MapObject& operator=(const MapObject& that);

            virtual ~MapObject(void);
            bool isDense(void);
            void setUpAnimation(Resources::AnimationTrigger, Graphics::Animation*);
            virtual const Graphics::Frame* currentSprite(void) const;

            virtual PlayStateContainer& onInspect(PlayStateContainer&);

            Util::Location location(int, int);
            Util::Location location(const Util::Location*);

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
            void triggerAnimation(Resources::AnimationTrigger event, int animationDurationMs);

            const Handler<MapObject, PlayStateContainer> onInspectFn(void) const;
        private:
            bool _isDense;

            int _x = 0;
            int _y = 0;
            Direction _facing = Direction::NONE;
            Graphics::Animation* _activeAnimation = NULL;
            std::map<Resources::AnimationTrigger, Graphics::Animation*> _animations = {};
            Handler<MapObject, PlayStateContainer> _onInspect;
    };
}

#endif
