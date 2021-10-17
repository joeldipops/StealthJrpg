#ifndef PARTY_H_INCLUDED
#define PARTY_H_INCLUDED

#include "mapObject.h"
#include "../res/templates.h"
#include "pc.h"

using namespace Resources;

namespace Play {
    class Party : public MapObject {
        public:
            Party(void);
            Party(std::vector<PC*>);
            ~Party(void);
            PC* leader(void) const;
            const std::vector<PC*> members(void) const;
            virtual const SpriteDefinition* currentSprite(void) const;
            PC* addLeader(const PCTemplate&);
            PC* addMember(const PCTemplate&);
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

            const std::vector<Rune*> runeCollection(void) const;
            void addRunes(Rune*);
            void addRunes(std::vector<Rune*>);
            std::vector<Rune*> _runeCollection;
        protected:
            void image(const MapObject*);

        private:
            std::vector<PC*> _members;
            std::vector<PC*> _bench;
            static MapObjectTemplate ctrTmpl;

    };
}
#endif
