#include "statsViewManager.h"

#include "../res/strings.h"
#include "../play/gameMap.h"
#include "../util/assetCache.h"

namespace View {
    using std::string;

    using Graphics::Sprite;
    using Play::GameMap;
    using Play::PlayState;
    using Play::PC;
    using Resources::Strings;
    using Util::AssetCache;

    StatsViewManager::StatsViewManager(SDL_Renderer* r, SDL_Rect v, AssetCache* a)
     : ViewManager(r, v, a) {}

    void StatsViewManager::setMapState(const GameMap* gameMap, const Play::PlayState state, int selectedMemberIndex) {
        lock();

        _map = gameMap;
        _state = state;
        _selectedMemberIndex = selectedMemberIndex;

        unlock();
    }

    void StatsViewManager::render() {
        ViewManager::render();
        fillViewport(BG_COLOUR);
        drawBorder(DEFAULT_BORDER_WIDTH, &TEXT_COLOUR);

        SDL_Rect rect;
        SDL_Rect port = SDL_Rect {1, 1, (viewPort().w / 2) - 5, 80};

        lock();
        if (_map != NULL) {
            for(natural i = 0; i < _map->party()->members().size(); i++) {
                const PC* pc = _map->party()->members().at(i);
                const SDL_Colour* colour = _state == PlayState::Combat && _selectedMemberIndex != int(i)
                    ? &TEXT_COLOUR
                    : &SELECTED_COLOUR
                ;

                // Render the character potrait
                Sprite* portrait = assets()->getSprite(pc->portraitFileName());
                SDL_RenderCopy(renderer(), portrait->texture(), portrait->stencil(), &port);
                int radius = port.h / 2;
                int x = port.x + port.w + radius;
                int y = port.y + radius;

                if (_state == PlayState::Combat && pc->isBlocked()) {
                    int degree = 3.6 * pc->elapsedWait();
                    if (degree > 0) {
                        drawSector(x, y, radius, 180, degree + 180);
                    }
                }

                string label = Strings::Stamina;
                string stamina = std::to_string(pc->stamina());
                rect = SDL_Rect{DEFAULT_BORDER_WIDTH + 2, port.h + port.y, viewPort().w - 75, 20};
                SDL_RenderCopy(renderer(), formatFontTexture(label, colour), NULL, &rect);
                rect = SDL_Rect{rect.x + rect.w + 15, rect.y, 40, rect.h};
                SDL_RenderCopy(renderer(), formatFontTexture(stamina, colour), NULL, &rect);

                port = SDL_Rect { port.x, rect.y + rect.h, port.w, port.h };
            }
        }
        unlock();
    }
}