#include "npc.h"
#include "gameMap.h"

namespace Play {
    using Resources::EnemyTemplate;
    using Util::AssetCache;

    // Lifecycle

    /**
     * Constructor.
     */
    NPC::NPC(const EnemyTemplate& tmpl, MobType type_, AssetCache* cache)
     : Mob(tmpl, type_, cache) {
        _movementDelay = tmpl.MovementDelay;
    }

    /**
     * Constructor
     */
    NPC::NPC(const EnemyTemplate& tmpl, AssetCache* cache)
     : NPC(tmpl, MobType::NPC, cache) {}

    /**
     * Destructor
     */
     NPC::~NPC(void) {}


    // Properties

    /**
     * The NPC should move after each _movementDelay ms.
     */
    int NPC::movementDelay(void) const { return _movementDelay; }


    // Methods

    /**
     * NPCs move around randomly. (I dunno what I was thinking here.  Obviously some will pace and some will stand still.....)
     */
    bool NPC::aiMove(GameMap& map_) {
        int dX = 0;
        int dY = 0;

        block(SDL_GetTicks() + _movementDelay + (rand() % 200 - 100));

        if (dX == 0 && dY == 0) {
            return false;
        }

        return map_.moveMob(this, x() + dX, y() + dY);
    }
}
