#ifndef MAGICTYPEDEFS_H_INCLUDED
#define MAGICTYPEDEFS_H_INCLUDED

#include <vector>

namespace Play {
    class Combatable;
    class Mob;
    class BattleField;
}

namespace Magic { class Command; }

namespace Magic {
    typedef Play::Combatable* (*Targeter)(Play::Mob*, Play::BattleField*);
    typedef std::vector<Play::Combatable*> (*MultiTargeter) (Play::Mob*, Play::BattleField*);
    typedef Play::Combatable* (*Selecter) (Play::Mob*, Play::BattleField*, std::vector<Play::Combatable*>);
    typedef void (*Action) (Play::Combatable*, Play::Combatable*, int, int);

    /**
    * Casts a spell or carries out some other in-combat command.
    * @param _this The command being carried out.
    * @param battlefield holds various data on combat currently in progress.
    * @return The time before the mob that made the command can act again.
    */
    typedef int (*Effect)(Magic::Command* context, Play::Mob*, Play::BattleField*);
}

#endif
