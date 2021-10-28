#include "playViewManager.h"

namespace View {
    PlayViewManager::PlayViewManager(
        MapViewManager* mapView, ControlViewManager* controlView, StatsViewManager* statsView, MiniMapViewManager* miniMapView, 
        SDL_Renderer* r, SDL_Rect v, Util::AssetCache* a
    ) : ViewManager(r, v, a) {
        _mapViewManager = mapView;
        _controlViewManager = controlView;
        _statsViewManager = statsView;
        _miniMapViewManager = miniMapView;
    }

    void PlayViewManager::render() {
        SDL_SetRenderDrawColor(renderer(), 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer());

        if (_mapViewManager != NULL) {
            _mapViewManager->render();
        }
        
        if (_controlViewManager != NULL) {
            _controlViewManager->render();
        }
        
        if (_statsViewManager != NULL) {
            _statsViewManager->render();
        }
        
        if (_miniMapViewManager != NULL) {
            _miniMapViewManager->render();
        }

        SDL_RenderPresent(renderer());
    }
}