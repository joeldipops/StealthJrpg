#ifndef PLAYSTATEMANAGER_H_INCLUDED
#define PLAYSTATEMANAGER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <SDL2/SDL.h>

#include "../stateManager.h"
#include "gameMap.h"
#include "mob.h"
#include "../mapFileBlock.h"
#include "../menuManager.h"
#include "enemy.h"
#include "combatManager.h"
#include "pc.h"
#include "party.h"
#include "../view/playViewManager.h"

namespace View {
    class ControlViewManager;
    class StatsViewManager;
    class MapViewManager;
    class MiniMapViewManager;
}

namespace Play {
    struct PlayStateContainer {
        PlayState State;
        std::string Message;
        GameMap* Map;
    };

    class PlayStateManager : public Core::StateManager<Play::PlayState, Core::CoreState> {
        public:
            PlayStateManager(SDL_Renderer*, View::RenderManager*, Util::AssetCache*);
            ~PlayStateManager(void);
            Core::CoreState start(Party&);
        private:
            // Set up
            Play::GameMap* loadMap(void);
            void render(void);
            void renderTerrain();
            void renderMobs();
            void renderHud();
            //std::vector<char> readFile(const char*);
            void writeMapFile(const std::string& fileName, const int width, const int height, const std::vector<Persistence::MapFileBlock>* data);

            // Main Loop
            bool processMovementState(void);
            bool processMessage(void);
            bool processInspectCommand(Party*);
            bool processCancel(void);
            bool moveMob(MapObject*, Core::InputPress);

            // Util
            void exit(const Core::CoreState = Core::CoreState::Exit);
            PlayStateContainer buildEventData(void) const;
            void writeBackEventData(const PlayStateContainer& data);

            // Properties
            std::string _message;
            View::PlayViewManager* _playView = nullptr;
            View::ControlViewManager* _controlView = nullptr;
            View::StatsViewManager* _statsView = nullptr;
            View::MiniMapViewManager* _miniMapView = nullptr;
            View::MapViewManager* _mapView = nullptr;
            Play::GameMap* _map = nullptr;
            int _combatGraceTime = 0;
            int _lastMoveTime = 0;

            std::vector<Persistence::MapFileBlock> tempMapFile();
    };
}

#endif
