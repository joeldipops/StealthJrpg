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

    /**
     * Destructor.
     */
    RenderManager::~RenderManager() {
        stop();
    }

    // Methods

    /**
     * Set manager that will control what gets rendered each frame.
     */
    void RenderManager::setActiveManager(ViewManager* manager) {
        _lock.lock();
        _activeManager = manager;
        _lock.unlock();
    }

    /**
     * Removes current render manager so nothing will get rendered.
     */
    void RenderManager::clearActiveManager() {
        _activeManager = NULL;
    }

    /**
     * Start the rendering thread.
     */
    void RenderManager::start() {
        if (_isRunning) {
            stop();
        }

        _isRunning = true;
        _renderThread = new thread(&RenderManager::render, this);
    }

    /**
     * Stop the rendering thread.
     */
    void RenderManager::stop() {
        _isRunning = false;
        if (_renderThread != NULL) {
            _renderThread->join();
            delete _renderThread;
        }
    }

    // Private Functions

    /**
     * Call manager's render function every frame.
     */
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