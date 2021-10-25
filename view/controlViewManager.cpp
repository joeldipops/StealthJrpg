#include "controlViewManager.h"
#include "../res/strings.h"
#include "../play/mob.h"
namespace View {
    using std::string;
    using std::vector;

    using Play::Mob;
    using Play::PlayState;

    const SDL_Rect ControlViewManager::_runeControl = SDL_Rect { 0, 0, 50, 50 };

    // Lifecycle

    /**
     * Constructor
     */
    ControlViewManager::ControlViewManager(SDL_Renderer* r, SDL_Rect v, AssetCache* a) : ViewManager(r, v, a) {}


    // Properties
    natural ControlViewManager::lastDrawnCharCount(void) const { return _lastDrawnCharCount; }

    void ControlViewManager::setDetails(const Mob* pc, PlayState state, const string& message) {
        lock();

        _pc = pc;
        _state = state;
        _message = message;

        unlock();
    }


    // Methods
    void ControlViewManager::render() {
        _lastDrawnCharCount = 0;
        ViewManager::render();
        fillViewport(BG_COLOUR);

        lock();

        switch(_state) {
            case PlayState::Movement:
            case PlayState::Message:
                if (_message.size() > 0) {
                    writeMessage(_message);
                } else {
                    writeHeading();
                }
                break;
            case PlayState::Combat: {
                if (_pc == nullptr) {
                    break;
                }
                vector<Command*> commands = _pc->commands();

                vector<MenuItem*> items;
                items.insert(items.begin(), commands.begin(), commands.end());

                SDL_Rect control {0, 0, 350, 50 };
                if (_pc->isBlocked()) {
                    drawControls(items, -1);
                } else {
                    drawControls(items, _pc->selectedCommandIndex(), nullptr, &control);
                }
                break;
            }
            default: break;

        }
        unlock();

        drawBorder(DEFAULT_BORDER_WIDTH, &TEXT_COLOUR);
    }

    void ControlViewManager::drawOptionBox(
        const SDL_Rect& rect,  const MenuItem* item, int borderWidth, const SDL_Colour& bgColour, const SDL_Colour& fgColour, const SDL_Colour& textColour
    ) {
        const int offset = DEFAULT_BORDER_WIDTH + 5;

        SDL_Rect posRect {
            rect.x + offset,
            rect.y + offset,
            rect.w,
            rect.h
        };

        // Control is a word.
        if (item->name().size()) {
            SDL_Rect textRect { posRect.x + controlBorderWidth * 2, posRect.y + controlBorderWidth, int(item->name().size()) * letterSize.w, letterSize.h };
            ViewManager::drawOptionBox(textRect, item, 0, bgColour, fgColour, textColour);
            drawBorder(posRect, borderWidth, &textColour, true);
            return;
        }

        // Control is a spell

        Command* command = (Command*) item;
        SDL_Rect runeRect { posRect.x, posRect.y, _runeControl.w, _runeControl.h };

        for (Rune* r : command->components()) {
            ViewManager::drawOptionBox(runeRect, r, 0, bgColour, fgColour, textColour);
            runeRect.x += _runeControl.w;
        }
        drawBorder(posRect, borderWidth, &textColour, true);
    }

    /**
     * Draws a message in the view, such as dialogue or information
     */
    void ControlViewManager::writeMessage(const string& message) {
        SDL_Rect vp = viewPort();
        vp.x = vp.x + 4;
        vp.y = vp.y + 4;
        vp.w = vp.w - 8;
        vp.h = vp.h - 8;
        SDL_Rect letterSize {0, 0, vp.h / 4, vp.h / 4};
        _lastDrawnCharCount = drawMessage(message, letterSize, viewPort(), false);
    }

    void ControlViewManager::writeHeading(void) {
        using namespace Resources;
        SDL_Texture* texture = formatFontTexture(Strings::Heading, &SELECTED_COLOUR);
        SDL_Rect textArea = SDL_Rect { viewPort().x + 20, viewPort().y + 5, viewPort().w - 40, viewPort().h - 10 };
        SDL_RenderCopy(renderer(), texture, NULL, &textArea);
    }
}
