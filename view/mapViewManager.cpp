#include "mapViewManager.h"
#include "../play/gameMap.h"
#include "../util/assetCache.h"
#include "../graphics/sprite.h"

namespace View {
    using Play::GameMap;
    using Play::MapCell;
    using Play::MapObject;
    using Play::Mob;
    using Graphics::Frame;
    using Graphics::Sprite;

    /**
     * Constructor passes through to base class.
     */
    MapViewManager::MapViewManager(SDL_Renderer* r, SDL_Rect v, Util::AssetCache* a) : ViewManager(r, v, a) {}

    /**
     * Sets up the next render
     * @param gameMap The contents of this map to the window.
     * @param state Rendering may differ depending on the current state.
     */
    void MapViewManager::setMapState(const GameMap* gameMap, const Play::PlayState state) {
        lock();

        _map = gameMap;
        _state = state;

        unlock();
    }


    /**
     * Renders the map.
     */
    void MapViewManager::render() {
        // Render Map
        ViewManager::render();

        lock();
        if (_map != NULL) {
            SDL_Rect visible = _map->visible();

            renderTerrain(_map, visible);
            renderContents(_map, visible);
        }
        unlock();
    }

    /**
     * Renders each terrain in the map.
     * @param mapData The map containing terrain data.
     */
    void MapViewManager::renderTerrain(const GameMap* gameMap, const SDL_Rect& visible) {
        const std::string blank = "hidden.png";

        for(int y = visible.y; y < visible.h; y++) {
            for(int x = visible.x; x < visible.w; x++) {
                if (x >= gameMap->width() || y >= gameMap->height()) {
                    continue;
                }

                SDL_Rect rect = { (x - visible.x) * CELL_WIDTH, (y - visible.y) * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT };
                const Sprite* frame = NULL;

                if (x >= 0 && y >= 0) {
                    const MapCell* cell = gameMap->getCell(x, y);
                    if (cell != nullptr) {
                        frame = cell->terrain()->currentSprite();
                    } else {
                        frame = assets()->getSprite(blank);
                    }
                } else {
                    frame = assets()->getSprite(blank);
                }

                if (frame != NULL) {
                    SDL_RenderCopy(renderer(), frame->texture(), frame->stencil(), &rect);
                }
            }
        }
    }

    /**
     * Renders each mob in the map.
     * @param mobs The list of mobs to render.
     */
    void MapViewManager::renderContents(const GameMap* gameMap, const SDL_Rect& visible) {
        for (const MapObject* mob : gameMap->contents()) {
            const int x = mob->x();
            const int y = mob->y();
            if (x < 0 || x > gameMap->width()) {
                continue;
            }
            if (y < 0 || y > gameMap->height()) {
                continue;
            }

            // Mob is not visible.
            if (x < visible.x || x > visible.w) {
                continue;
            }
            if (y < visible.y || y > visible.h) {
                continue;
            }

            SDL_Rect rect = {
                (x - visible.x) * CELL_WIDTH + (CELL_WIDTH / 4),
                (y - visible.y) * CELL_HEIGHT + (CELL_HEIGHT / 4),
                CELL_WIDTH / 2, CELL_HEIGHT / 2
            };

            Sprite* sprite = (Sprite*) mob->currentSprite();
            if (sprite != NULL) {
                SDL_RenderCopy(renderer(), sprite->texture(), sprite->stencil(), &rect);
            }

            if (mob->isMob()) {
                renderHealthBar(*(Mob*)mob, x - visible.x, y - visible.y);
            }
        }

        Mob& leader = *(Mob*)gameMap->party()->leader();
        renderHealthBar(leader, leader.x() - visible.x, leader.y() - visible.y);
    }

    void MapViewManager::renderHealthBar(const Mob& mob, int x, int y) {
        const int barWidth = 2;
        SDL_Rect rect = {
            x * CELL_WIDTH + 1,
            y * CELL_HEIGHT + 2,
            CELL_WIDTH - 4,
            barWidth,
        };

        SDL_Colour colour = SDL_Colour {0x00, 0x00, 0x00, 0xFF};
        drawBorder(rect, 1, &colour , false);
        SDL_SetRenderDrawColor(renderer(), 0x00, 0xFF, 0x00, 0xFF);
        int w = ceil( (double(rect.w) / double(mob.maxStamina())) * mob.stamina() );

        rect = {
            rect.x,
            rect.y,
            w,
            rect.h
        };

        SDL_RenderFillRect(renderer(), &rect);
    }
}


