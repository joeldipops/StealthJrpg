#include "titleStateManager.h"
#include "../util/events.h"

namespace Play {
    using std::vector;

    using Core::CoreState;
    using Core::Event;
    using Core::InputPress;
    using Core::MenuItem;
    using Resources::Strings;
    using View::RenderManager;
    using View::TitleViewManager;

    const MenuItem TitleStateManager::START = MenuItem(Strings::Start);
    const MenuItem TitleStateManager::QUIT = MenuItem(Strings::Quit);
    const MenuItem TitleStateManager::CONTINUE = MenuItem(Strings::Continue);

    /**
     * Constructor
     */
    TitleStateManager::TitleStateManager(SDL_Renderer* r, RenderManager* rm, Util::AssetCache* a)
     : StateManager(r, rm, a) {
        _view = TitleViewManager(renderer(), SDL_Rect {0, 0, 1200, 800}, assets());
        _menu = std::vector<MenuItem> {START, CONTINUE, QUIT};
        state(TitleState::Normal);
    }

    TitleStateManager::~TitleStateManager() {

    }

    /**
     * Sets up graphics then Starts the main loop for this state.
     * @returns the state the core loop should be in when the PlayState ends.
     */
    CoreState TitleStateManager::start(void) {
        renderManager()->setActiveManager(&_view);

        state(TitleState::Normal);
        result(CoreState::Exit);
        bool rerender = true;
        _selectedItemIndex = 0;
        TitleState oldState;
        while(state() != TitleState::TitleExit) {
            if(rerender) {
                render();
            } else {
                Util::sleep(50);
            }
            oldState = state();

            Event myEvent;
            while(eventManager.pollEvent(&myEvent) && oldState == state()) {
                SDL_Event event = *myEvent.InnerEvent;
                switch(event.type) {
                    case SDL_QUIT:
                        state(TitleState::TitleExit);
                        result(CoreState::Exit);
                        continue;
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym) {
                            case SDLK_q:
                            case SDLK_ESCAPE:
                                state(TitleState::TitleExit);
                                continue;
                            case SDLK_w:
                                rerender = moveCursor(InputPress::UP);
                                break;
                            case SDLK_a:
                                rerender = moveCursor(InputPress::LEFT);
                                break;
                            case SDLK_s:
                                rerender = moveCursor(InputPress::DOWN);
                                break;
                            case SDLK_d:
                                rerender = moveCursor(InputPress::RIGHT);
                                break;
                            case SDLK_RETURN:
                            case SDLK_RIGHTBRACKET:
                                rerender = processCommand();
                                break;
                        }
                        break;
                }
            }
        }

        renderManager()->clearActiveManager();

        return result();
    }

    void TitleStateManager::render(void) {
        vector<MenuItem*> pointers = Util::toPointers<MenuItem>(_menu);
        _view.setControls(pointers, _selectedItemIndex);
    }

    bool TitleStateManager::moveCursor(const InputPress input) {
        int result = StateManager::moveCursor(input, _selectedItemIndex, _menu.size(), _menu.size());
        if (result != _selectedItemIndex) {
            _selectedItemIndex = result;
            return true;
        }

        return false;
    }

    bool TitleStateManager::processCommand(void) {
        MenuItem command = _menu.at(_selectedItemIndex);

        if (command.equals(START)) {
            state(TitleState::TitleExit);
            result(CoreState::Play);
        } else if (command.equals(QUIT)) {
            state(TitleState::TitleExit);
            result(CoreState::Exit);
        } else if (command.equals(CONTINUE)) {
            state(TitleState::TitleExit);
            result(CoreState::Load);
        }
        return false;
    }
}
