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

    RenderManager::~RenderManager() {
        stop();
    }

    // Methods

    void RenderManager::setActiveManager(ViewManager* manager) {
        _lock.lock();
        _activeManager = manager;
        _lock.unlock();
    }

    void RenderManager::clearActiveManager() {
        _activeManager = NULL;
    }

    void RenderManager::start() {
        if (_isRunning) {
            stop();
        }

        _isRunning = true;
        _renderThread = new thread(&RenderManager::render, this);
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
            _lock.lock();
            if (_activeManager != NULL) {
                _activeManager->render();
            }
            _lock.unlock();

            Util::sleep(_renderIntervalMs);
        }
    }

}