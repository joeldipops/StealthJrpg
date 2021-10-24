#ifndef VICTORYVIEWMANAGER_H_INLCUDED
#define VICTORYVIEWMANAGER_H_INLCUDED

#include "viewManagerMenuToolsBase.h"

namespace Util { class AssetCache; }
namespace Play { class Party; }

namespace View {
    class VictoryViewManager : public ViewManagerMenuToolsBase {
        public:
            VictoryViewManager(SDL_Renderer*, SDL_Rect, Util::AssetCache*);
            void setParty(const Play::Party*);
            void render(void);
        private:
            const Play::Party* _party;
    };
}

#endif
