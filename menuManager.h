#ifndef MENUMANAGER_H_INCLUDED
#define MENUMANAGER_H_INCLUDE

#include <SDL2/SDL.h>

#include "stateManager.h"
#include "play/mob.h"
#include "view/menuViewManager.h"
#include "globalConstants.h"
#include "persistence/saveLoad.h"
#include "res/strings.h"
#include "util/utils.h"
#include "magic/spell.h"

namespace Play
{
    class MenuManager : public Core::StateManager<Play::MenuState, Play::PlayState>
    {
        public:
            MenuManager(SDL_Renderer*, Util::AssetCache*);
            Play::PlayState start(Play::Party& party);
            Play::PlayState start(void);

        private:
            static const Core::MenuItem MAGIC;
            static const Core::MenuItem SAVE;
            static const Core::MenuItem PARTY;

            natural selectedSpellLength(PC*) const;
            bool moveCursor(Play::Party& party, Core::InputPress input);
            bool moveCursorSideways(Play::Party& party, Core::InputPress input);

            // What happens when you hit ok when on various menu items.
            bool processMenuCommand(const Play::Party& party);
            bool processMemberCommand(void);
            bool processRuneCommand(const Play::Party& party);
            bool processSpellCommand(Play::Party& party);
            bool processComponentCommand(void);
            bool processReorderMemberCommand(Play::Party& party);

            bool processCommand(Play::Party& party);
            bool processCancel(Play::Party& party);

            bool cast(Play::Party&, Play::Mob&, int);

            View::MenuViewManager _viewManager;
            int _selectedMenuIndex;
            int _selectedMemberIndex;
            int _selectedSpellIndex;
            int _selectedRuneIndex;
            int _selectedComponentIndex;
            int _selectedPositionIndex;
            std::vector<Core::MenuItem> _menu;
            std::string _message = "";
    };
}

#endif

