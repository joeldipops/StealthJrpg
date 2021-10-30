#include "stateManager.h"

namespace Core {
    using Play::PlayState;
    using Play::MenuState;
    using Play::TitleState;
    using Util::AssetCache;
    using View::RenderManager;

    /**
     * Constructor
     */
    template <typename S, typename P>
    StateManager<S, P>::StateManager(SDL_Renderer* renderer, RenderManager* renderManager, AssetCache* assets) {
        _renderer = renderer;
        _renderManager = renderManager;
        _assets = assets;
    }

    /**
     * Constructor
     */
    template <typename S, typename P>
    StateManager<S, P>::StateManager(SDL_Renderer* renderer, AssetCache* assets) {
        _renderer = renderer;
        _assets = assets;
    }    

    /**
     * Gets and sets the current internal state.
     */
    template <typename S, typename P>
    S StateManager<S, P>::state(void) const {
        return _state;
    }
    template <typename S, typename P>
    S StateManager<S, P>::state(S state_) {
        _state = state_;
        return _state;
    }

    /**
     * Gets and sets the current parent state
     */
    template <typename S, typename P>
    P StateManager<S, P>::result(void) const {
        return _result;
    }
    template <typename S, typename P>
    P StateManager<S, P>::result(P result_) {
        _result = result_;
        return _result;
    }

    /**
     * Gets the SDL renderer.
     */
    template <typename S, typename P>
    SDL_Renderer* StateManager<S, P>::renderer(void) {
        return _renderer;
    }

    template <typename S, typename P>
    RenderManager* StateManager<S, P>::renderManager(void) const { return _renderManager; };

    /**
     * Gets the asset cache.
     */
    template <typename S, typename P>
    AssetCache* StateManager<S, P>::assets(void) {
        return _assets;
    }

    /**
     * Moves the cursor around a menu.
     */
    template <typename S, typename P>
    const int StateManager<S, P>::moveCursor(const InputPress input, const int selectedIndex, const int numberOfItems, const int itemsPerColumn) {
        int index = selectedIndex;
        switch(input) {
            case InputPress::UP:
                if (index <= 0) {
                    return selectedIndex;
                }
                index--;
                break;
            case InputPress::LEFT:
                index -= itemsPerColumn;
                if (index < 0) {
                    return selectedIndex;
                }
                break;
            case InputPress::DOWN:
                if (index >= numberOfItems - 1) {
                    return selectedIndex;
                }
                index++;
                break;
            case InputPress::RIGHT:
                index += itemsPerColumn;
                if (index >= numberOfItems) {
                    return selectedIndex;
                }
                break;
        }

        return index;
    }

    template class StateManager<PlayState, CoreState>;
    template class StateManager<TitleState, CoreState>;
    template class StateManager<MenuState, PlayState>;
    template class StateManager<PlayState, PlayState>;
}