#include "titleViewManager.h"
#include "../util/assetCache.h"
namespace View {
    using std::vector;

    using Core::MenuItem;
    using Util::AssetCache;

    TitleViewManager::TitleViewManager() : ViewManager() {}

    TitleViewManager::TitleViewManager(SDL_Renderer* r, SDL_Rect v, AssetCache* a) 
     : ViewManager(r, v, a) {}

    void TitleViewManager::setControls(vector<MenuItem*> controls, int selectedIndex) {
        lock();
        _controls = controls;
        _selectedIndex = selectedIndex;
        unlock();
    }
    
    void TitleViewManager::render() {
        ViewManager::render();
        SDL_SetRenderDrawColor(renderer(), 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer());

        drawBorder(5, &TEXT_COLOUR);

        lock();
        if (_controls.size() > 0) {
            drawControls(_controls, _selectedIndex);
        }
        unlock();

        SDL_RenderPresent(renderer());
    }
}