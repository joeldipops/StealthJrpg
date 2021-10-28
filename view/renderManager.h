#ifndef RENDERMANAGER_H_INCLUDED
#define RENDERMANAGER_H_INCLUDED

#include <thread>

#include "viewManager.h"


namespace View {
    class RenderManager {
        public:
            RenderManager(int renderIntervalMs);
            ~RenderManager(void);
            void start(void);
            void stop(void);
            void setActiveManager(ViewManager* viewManager);
            void clearActiveManager(void);

        private:
            int _renderIntervalMs;
            ViewManager* _activeManager;
            bool _isRunning;
            void render(void);
            std::thread* _renderThread;
            std::mutex _lock;
    };
}

#endif