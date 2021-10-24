#ifndef MAPVIEWMANAGER_H_INCLUDED
#define MAPVIEWMANAGER_H_INCLUDED

#include "viewManager.h"

namespace Play { class Mob; }

namespace View {
    class MapViewManager : public ViewManager {
        public:
            MapViewManager(SDL_Renderer*, SDL_Rect, Util::AssetCache*);

            void setMapState(const Play::GameMap*, const Play::PlayState);
            void render(void);

        private:
            void renderHealthBar(const Play::Mob&, int x, int y);
            void renderContents(const Play::GameMap*, const SDL_Rect& visible);
            void renderTerrain(const Play::GameMap* gameMap, const SDL_Rect& visible);

            const Play::GameMap* _map = NULL;
            Play::PlayState _state = Play::PlayState::Exit;
    };
}

#endif
