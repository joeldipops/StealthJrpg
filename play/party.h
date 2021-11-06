#ifndef PARTY_H_INCLUDED
#define PARTY_H_INCLUDED

#include "mapObject.h"
#include "../res/templates.h"
#include "pc.h"
#include "../util/assetCache.h"

namespace Play {
    class Party : public MapObject {
        public:
            Party(Util::AssetCache*);
            Party(std::vector<PC*>, Util::AssetCache*);
            ~Party(void);
            PC* leader(void) const;
            const std::vector<PC*> members(void) const;
            virtual const Graphics::Frame* currentSprite(void) const;
            PC* addMember(const Resources::PCTemplate&, Util::AssetCache*);
            PC* removeMember(PC*);
            PlayStateContainer& onInspect(PlayStateContainer&);
            void buryTheDead(void);
            void endCombat(void);
            void getSpoils(BattleField& field);

            PC* memberAt(natural) const;
            int getIndexOf(const Mob*) const;
            void reorder(int, int);

            bool isDefeated(void) const;
            bool isPlayerParty(void) const;
            int x(int); using MapObject::x;
            int y(int); using MapObject::y;

            virtual Direction facing(void) const;
            virtual Direction facing(Direction);

            const std::vector<Magic::Rune*> runeCollection(void) const;
            void addRunes(Magic::Rune*);
            void addRunes(std::vector<Magic::Rune*>);
            std::vector<Magic::Rune*> _runeCollection;

        protected:
            PC* addLeader(PC*);

        private:
            std::vector<PC*> _members;
            std::vector<PC*> _bench;
            static Resources::MapObjectTemplate ctrTmpl;
    };
}
#endif
