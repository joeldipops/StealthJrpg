#ifndef STATEMANAGER_H_INCLUDED
#define STATEMANAGER_H_INCLUDED

#include <SDL2/SDL.h>

#include "globalConstants.h"
#include "view/renderManager.h"

namespace Util { class AssetCache; }

namespace Core {
    template<typename State, typename ParentState>
    class StateManager {
        public:
            StateManager(SDL_Renderer* renderer, View::RenderManager* renderManager, Util::AssetCache* assets);

            // TODO: Remove
            StateManager(SDL_Renderer* renderer, Util::AssetCache* assets);

        protected:
            virtual const int moveCursor(const Core::InputPress, const int, const int, const int);
            virtual State state(void) const;
            virtual State state(State);

            virtual ParentState result(void) const ;
            virtual ParentState result(ParentState);

            SDL_Renderer* renderer(void);
            Util::AssetCache* assets(void);
            View::RenderManager* renderManager(void) const;

        private:
            View::RenderManager* _renderManager;
            SDL_Renderer* _renderer;
            Util::AssetCache* _assets;
            State _state;
            ParentState _result;
    };
}

#endif
