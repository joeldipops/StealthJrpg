#ifndef INTROVIEWMANAGER_H_INCLUDED
#define INTROVIEWEMANAGER_H_INCLUDED

#include "viewManager.h"

namespace View {
    class TitleViewManager : public ViewManager {
        public:
            TitleViewManager(void);
            TitleViewManager(SDL_Renderer*, SDL_Rect, Util::AssetCache*);
            void setControls(const std::vector<Core::MenuItem*> controls, const int selectedIndex);
            void render(void);
        private:
            std::vector<Core::MenuItem*> _controls = {};
            int _selectedIndex = 0;

    };
}

#endif
