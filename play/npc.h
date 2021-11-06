#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "mob.h"

namespace Resources { struct EnemyTemplate; }

namespace Play {
    class GameMap;

    class NPC : public Mob {
        public:
            NPC(const Resources::EnemyTemplate&, MobType, Util::AssetCache*);
            NPC(const Resources::EnemyTemplate&, Util::AssetCache*);
            ~NPC(void);
            virtual bool aiMove(GameMap&);
        protected:
            int movementDelay(void) const;
        private:
            int _movementDelay;
    };
}

#endif
