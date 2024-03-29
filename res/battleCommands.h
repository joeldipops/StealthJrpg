#ifndef BATTLECOMMANDS_H_INCLUDED
#define BATTLECOMMANDS_H_INCLUDED

#include "../play/battleField.h"
#include "../play/mapObject.h"
#include "../magic/verb.h"
#include "../magic/modifier.h"
#include "../magic/noun.h"
#include "../play/mob.h"
#include "../magic/targetAll.h"
#include "../util/utils.h"

namespace Play { class Enemy; }
namespace Resources {
    struct Commands {
        // Non spell commands
        static int FLEE(Magic::Command*, Play::Mob*, Magic::SpellContext& field);
        static int ATTACK(Magic::Command* command, Play::Mob* actor, Magic::SpellContext& field);
    };
}
#endif
