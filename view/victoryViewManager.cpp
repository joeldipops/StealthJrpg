#include "victoryViewManager.h"

#include "../res/strings.h"
#include "../play/party.h"

namespace View {
    using Util::AssetCache;
    using Play::Party;

    // Lifecycle

    VictoryViewManager::VictoryViewManager(SDL_Renderer* r, SDL_Rect v, AssetCache* a)
     : ViewManagerMenuToolsBase(r, v, a) { }

    // Methods

    void VictoryViewManager::setParty(const Party* party) {
        lock();
        _party = party;
        unlock();
    }

    void VictoryViewManager::render() {
        using namespace Resources;
        const SDL_Rect controlView = {0, 0, 1200, 150};
        const SDL_Rect letterSize { 0, 0, 50, 50};
        ViewManager::render();
        fillViewport(BG_COLOUR);
        drawMessage(Strings::Victory, letterSize, controlView, false);

        SDL_Rect vp { viewPort().x, viewPort().y + 50, viewPort().w, viewPort().h - 50 };
        lock();

        renderPCs(*_party, -1, vp, -1, true);

        unlock();
    }
}
