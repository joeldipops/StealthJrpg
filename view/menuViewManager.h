#ifndef MENUVIEWMANAGER_H_INCLUDED
#define MENUVIEWMANAGER_H_INCLUDED

#include "../util/utils.h"
#include "viewManagerMenuToolsBase.h"
#include "../res/battleCommands.h"
#include "../play/pc.h"
#include "../globalConstants.h"
#include "../play/party.h"

namespace View {
    struct MenuViewModel {
        public:
            std::vector<Core::MenuItem> MenuItems;
            Play::MainMenuItem SelectedMenuItem;
            Play::MenuState state;
            int SelectedPCIndex;
            int SelectedSpellIndex;
            int SelectedComponentIndex;
            int SelectedRuneIndex;
            int SelectedPositionIndex;
    };

    class MenuViewManager : public ViewManagerMenuToolsBase {
        public:
            MenuViewManager() {};
            MenuViewManager(SDL_Renderer*, SDL_Rect, Util::AssetCache*);
            void render(const Play::Party&, const MenuViewModel&, const std::string* = nullptr);

        private:
            SDL_Rect _spellsVp;
            SDL_Rect _runesVp;
            SDL_Rect _mainVp;
            SDL_Rect _partyVp;

            void renderSpells(const Play::PC&, int, int);
            void renderRunes(const Play::Party&, int);

            static const SDL_Rect _runeControl;
    };
}

#endif
