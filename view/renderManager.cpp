#include "renderManager.h"

#include <thread>

#include "../util/utils.h"

namespace View {
    using std::thread;

    // Lifecycle

    /**
     * Constructor
     * @param renderIntervalMs Milliseconds between each render.
     */
    RenderManager::RenderManager(int renderIntervalMs) {
        _renderIntervalMs = renderIntervalMs;
        _activeManager = NULL;
        _renderThread = NULL;
    }

    // Methods

    void RenderManager::setActiveManager(ViewManager* manager) {
        _activeManager = manager;
    }

    void RenderManager::start() {
        if (_isRunning) {
            stop();
        }

        _isRunning = true;
        _renderThread = new thread(render);
    }

    void RenderManager::stop() {
        _isRunning = false;
        if (_renderThread != NULL) {
            _renderThread->join();
            delete _renderThread;
        }
    }

    // Private Functions


    void RenderManager::render() {
        while(_isRunning) {
            if (_activeManager != NULL) {
                _activeManager->render();
            }

            Util::sleep(_renderIntervalMs);
        }
    }

}