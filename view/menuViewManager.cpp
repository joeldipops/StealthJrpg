#include "menuViewManager.h"
#include "../res/strings.h"
#include "../magic/spell.h"
#include "../util/assetCache.h"

namespace View {
    using std::string;
    using std::vector;

    using Core::MenuItem;
    using Graphics::Sprite;
    using Magic::Rune;
    using Magic::Spell;
    using Play::MainMenuItem;
    using Play::Party;
    using Play::PC;
    using Play::MenuState;
    using Resources::Strings;
    using Util::AssetCache;


    const SDL_Rect MenuViewManager::_runeControl = SDL_Rect { 6, 6, 60, 60 };
    /**
     * Constructor.
     */
    MenuViewManager::MenuViewManager(SDL_Renderer* r, SDL_Rect v, AssetCache* a)
     : ViewManagerMenuToolsBase(r, v, a) {
        _mainVp = SDL_Rect {v.x, v.y, 190, v.h };
        _spellsVp = SDL_Rect {v.x + _mainVp.w, v.y, v.w - _mainVp.w, 550};
        _runesVp = SDL_Rect {_spellsVp.x, v.y + _spellsVp.h, _spellsVp.w, v.h - _spellsVp.h };
        _partyVp = SDL_Rect { v.x + _mainVp.w, v.y, v.w - _mainVp.w, v.h };
    }

    /**
     * Renders the selectable list of runes
     * @param pc
     * @param runeIndex The rune that the cursor is on.
     */
    void MenuViewManager::renderRunes(int runeIndex) {
        vector<Rune*> runes = _party->runeCollection();
        vector<MenuItem*> items = vector<MenuItem*> (0);
        MenuItem item = MenuItem("");
        items.push_back(&item);
        items.insert(items.end(), runes.begin(), runes.end());
        drawControls(items, runeIndex, &_runesVp, &_runeControl);
    }

    /**
     * Renders the PC's list of constructed spells.
     * @param pc the PC
     * @param spellIndex Index of the spell currently being edited.
     * @param componnentPosition Position of the component that can be changed.
     */
    void MenuViewManager::renderSpells(const PC& pc, int spellIndex, int componentPosition) {
        Sprite* valid = assets()->getSprite(RESOURCE_LOCATION + "valid.png");
        Sprite* invalid = assets()->getSprite(RESOURCE_LOCATION + "invalid.png");

        SDL_Rect rect = SDL_Rect { _spellsVp.x + marginLeft, _spellsVp.y, WIDTH, _control.y + _control.h };

        for (int i = 0; i < int(pc.spellSlots()); i++) {
            int position = -1;
            if (i == spellIndex) {
                position = componentPosition;
            }
            vector<MenuItem*> menuItems = vector<MenuItem*>(0);

            if (i < int(pc.spells().size())) {
                const Spell* command = (Spell*) pc.spells().at(i);
                vector<Rune*> runes = command->components();

                MenuItem emptySlot = MenuItem();

                menuItems.insert(menuItems.end(), runes.begin(), runes.end());

                if (runes.size() < pc.runeSlots()) {
                    menuItems.push_back(&emptySlot);
                }

                SDL_Rect validRect = SDL_Rect { rect.x - 30, rect.y + cursorYOffset, 30, 30 };
                if (command->isValid(true)) {
                    SDL_RenderCopy(renderer(), valid->texture(), valid->stencil(), &validRect);
                } else {
                    SDL_RenderCopy(renderer(), invalid->texture(), invalid->stencil(), &validRect);
                }

                // if position is less than -1 a different button (eg. "Cast") is selected.
                if (i == spellIndex && position >= -1) {
                    drawHorizontalControls(menuItems, position, &rect, &_runeControl, &SELECTED_COLOUR, &HIGHLIGHTED_COLOUR);
                } else {
                    drawHorizontalControls(menuItems, position, &rect, &_runeControl);
                }

                // Draw button to let us use the spell.
                if (command->isValid(true) && i == spellIndex) {
                    SDL_Rect castRect { rect.w - (_menuControl.w + 10), rect.y + 10, _menuControl.w, _menuControl.h };
                    if (position == -2) {
                        drawOptionBox(castRect, Strings::Cast, borderWidth, BG_COLOUR, SELECTED_COLOUR, SELECTED_COLOUR);
                    } else {
                        drawOptionBox(castRect, Strings::Cast, borderWidth, BG_COLOUR, TEXT_COLOUR, TEXT_COLOUR);
                    }
                }
            } else {
                MenuItem emptySlot = MenuItem();
                menuItems.push_back(&emptySlot);
                if (i == spellIndex) {
                    drawHorizontalControls(menuItems, position, &rect, &_menuControl, &SELECTED_COLOUR, &HIGHLIGHTED_COLOUR);
                } else {
                    drawHorizontalControls(menuItems, position, &rect, &_menuControl);
                }
            }

            rect = SDL_Rect { rect.x, rect.y + rect.h, rect.w, rect.h};
        }
    }

    void MenuViewManager::setData(const Party* party, MenuViewModel model, const string* message) {
        lock();
        _party = party;
        _model = model;
        _message = message;
        unlock();
    }


    /**
     * Renders menu related  elements to the screen.
     */
    void MenuViewManager::render() {
        ViewManager::render();
        fillViewport(BG_COLOUR);
        drawBorder(borderWidth, &TEXT_COLOUR);

        lock();

            auto pointers = Util::toPointers(_model.MenuItems);

            // Highlight the drilled-into item.
            if (_model.state != MenuState::SelectMenu) {
                auto copy = *pointers.at(_model.SelectedMenuItem);
                copy.colour(HIGHLIGHTED_COLOUR);
                pointers.at(_model.SelectedMenuItem) = &copy;
            }

            drawControls(pointers, int(_model.SelectedMenuItem), &_mainVp, &_menuControl, false);

            if (_party != NULL) {
                switch(_model.SelectedMenuItem) {
                    case MainMenuItem::MagicSelected:
                    case MainMenuItem::PartySelected:
                        switch (_model.state) {
                            case MenuState::SelectMenu:
                            case MenuState::SelectMember:
                                renderPCs(*_party, _model.SelectedPCIndex, _partyVp);
                                break;
                            case MenuState::ReorderMember:
                                renderPCs(*_party, _model.SelectedPCIndex, _partyVp, _model.SelectedPositionIndex);
                                break;
                            default: {
                                drawBorder(_spellsVp, borderWidth, &TEXT_COLOUR, true);
                                drawBorder(_runesVp, borderWidth, &TEXT_COLOUR, true);
                                renderSpells(*_party->memberAt(_model.SelectedPCIndex), _model.SelectedSpellIndex, _model.SelectedComponentIndex);
                                renderRunes(_model.SelectedRuneIndex);
                            }
                        }
                        break;
                    case MainMenuItem::SaveSelected:
                    default:
                        break;
                }
            }

        if (_message != nullptr) {
            drawMessage(*_message, letterSize, messageBoxOuter, true);
        }
        unlock();

        SDL_RenderPresent(renderer());
    }
}
