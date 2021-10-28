#ifndef MAGICTYPEDEFS_H_INCLUDED
#define MAGICTYPEDEFS_H_INCLUDED

#include <vector>
#include "../globalConstants.h"

namespace Play {
    class Mob;
    class BattleField;
    class Combatable;
}

namespace Magic {
    class SpellContext;
    struct SpellData {
        Stat stat;
        Modality modality;
        float effect;
        float cost;
        float duration;
    };

    class Command;

    /**
     * Targets a specific Mob.
     */
    typedef Play::Combatable* (*Targeter)(Play::Mob*, SpellContext&, SpellData&);

    /**
     * Chooses a list of candidates to be the target of the spell.
     */
    typedef std::vector<Play::Combatable*> (*MultiTargeter) (Play::Mob*, SpellContext&, SpellData&);

    /**
     * Selects a target from a list of candidates.
     */
    typedef Play::Combatable* (*Selecter) (Play::Mob*, SpellContext&, const std::vector<Play::Combatable*>&, SpellData&);

    /**
     * Performs an action as part of a spell.
     */
    typedef void (*Action) (Play::Combatable*, Play::Combatable*, int, int, SpellData&);

    /**
    * Casts a spell or carries out some other in-combat command.
    * @param _this The command being carried out.
    * @param battlefield holds various data on combat currently in progress.
    * @return The time before the mob that made the command can act again.
    */
    typedef int (*Effect)(Command* context, Play::Mob*, SpellContext&);

    /**
     * Performs operations and transformations on the spell itself without changing the target, source or effect.
     */
    typedef SpellData& (*MetaAction)(SpellData&);
}

#endif
