#ifndef PLAYVIEWMANAGER_H_INCLUDED
#define PLAYVIEWMANAGER_H_INCLUDED

#include "viewManager.h"
#include "mapViewManager.h"
#include "controlViewManager.h"
#include "statsViewManager.h"
#include "miniMapViewManager.h"

namespace View {
    class PlayViewManager : public ViewManager {
        public:
            PlayViewManager() {};
            PlayViewManager(MapViewManager*, ControlViewManager*, StatsViewManager*, MiniMapViewManager*, SDL_Renderer*, SDL_Rect, Util::AssetCache*);
            void render(void);
        private:
            MapViewManager* _mapViewManager = NULL;
            ControlViewManager* _controlViewManager = NULL;
            StatsViewManager* _statsViewManager = NULL;
            MiniMapViewManager* _miniMapViewManager = NULL;
    };
}

#endif