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

namespace Play {
    struct PlayStateContainer;
    typedef PlayStateContainer& (*PlayEventHandler)(MapObject*, PlayStateContainer&);
    class MapObject {
        public:
            MapObject(const Resources::MapObjectTemplate&);

            MapObject& operator=(const MapObject& that);

            virtual ~MapObject(void);
            bool isDense(void);
            void setUpAnimation(Resources::AnimationTrigger, Graphics::Animation*);
            virtual const Graphics::SpriteDefinition* currentSprite(void) const;
            std::string imageFileName(const std::string&);
            std::string imageFileName(void) const;

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
            MapObject(const MapObject& that);
            //MapObject& operator=(const MapObject& that);

            bool _isDense;
            std::string _imageFileName;
            int _x = 0;
            int _y = 0;
            Direction _facing = Direction::NONE;
            Graphics::Animation* _activeAnimation = nullptr;
            std::map<Resources::AnimationTrigger, Graphics::Animation*> _animations = {};
            Handler<MapObject, PlayStateContainer> _onInspect;
    };
}

#endif
