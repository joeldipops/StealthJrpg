#ifndef NOUN_H_INCLUDED
#define NOUN_H_INCLUDED

#include <vector>

#include "word.h"
#include "modifier.h"
#include "../play/mapObject.h"
#include "../play/battleField.h"

namespace Play { class Mob; }
namespace Magic {
    class Noun;
    typedef Play::Combatable* (*NounTargeter)(Noun* context, Play::Mob* caster, SpellContext& field, SpellData& data);

    class Noun : public Word {
        public:
            Noun(){};
            Noun(Rune* properNoun);
            Noun(Rune* aux, Rune* adj, Rune* noun);
            Noun(Rune* adj, Rune* noun);
            std::vector<Play::Combatable*> acquireCandidates(Play::Mob*, SpellContext&);
            WordType type(void) const;
            Play::Combatable* acquireTarget(Play::Mob*, SpellContext&);

        private:
            MultiTargeter _multiTargeter;

            MultiTargeter _findCandidates;
            Targeter _target;
            Selecter _select;
            Modality _modality;

            NounTargeter _targetWrapper;

            friend Play::Combatable* properNounAcquire(Noun*, Play::Mob* caster, SpellContext& field, SpellData& data);
            friend Play::Combatable* auxAdjNounAcquire(Noun*, Play::Mob* caster, SpellContext& field, SpellData& data);
            friend Play::Combatable* adjNounAcquire(Noun*, Play::Mob* caster, SpellContext& field, SpellData& data);
    };
    Play::Combatable* properNounAcquire(Noun* context, Play::Mob* caster, SpellContext& field, SpellData& data);
    Play::Combatable* auxAdjNounAcquire(Noun*, Play::Mob* caster, SpellContext& field, SpellData& data);
    Play::Combatable* adjNounAcquire(Noun*, Play::Mob* caster, SpellContext& field, SpellData& data);
}

#endif
