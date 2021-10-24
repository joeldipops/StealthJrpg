#ifndef STATSVIEWMANAGER_H_INCLUDED
#define STATSVIEWMANAGER_H_INCLUDED

#include "viewManager.h"

namespace Util { class AssetCache; }
namespace Play {class GameMap; }

namespace View {
    class StatsViewManager : public ViewManager {
        public:
            StatsViewManager(SDL_Renderer*, SDL_Rect, Util::AssetCache*);
            void setMapState(const Play::GameMap*, const Play::PlayState, int = -1);
            void render();

        private:
            const Play::GameMap* _map = NULL;
            Play::PlayState _state = Play::PlayState::Exit;
            int _selectedMemberIndex = -1;
    };
}

#endif
