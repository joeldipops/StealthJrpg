#ifndef COMBATVIEWMANAGER_H_INCLUDED
#define COMBATVIEWMANAGER_H_INCLUDED

#include "viewManager.h"
#include "mapViewManager.h"
#include "controlViewManager.h"
#include "statsViewManager.h"
#include "miniMapViewManager.h"
#include "victoryViewManager.h"

#include "../util/assetCache.h"

namespace View {
    class CombatViewManager : public ViewManager {
        public:
            CombatViewManager(
                MapViewManager* mapView,
                ControlViewManager* controlView,
                StatsViewManager* statsView,
                MiniMapViewManager* miniMapView,
                VictoryViewManager* victoryView,
                SDL_Renderer* r,
                SDL_Rect v,
                Util::AssetCache* a
            );

            void render(void);
        private:
            MapViewManager* _mapViewManager = NULL;
            ControlViewManager* _controlViewManager = NULL;
            StatsViewManager* _statsViewManager = NULL;
            MiniMapViewManager* _miniMapViewManager = NULL;
            VictoryViewManager* _victoryViewManager = NULL;
    };
}

#endif
