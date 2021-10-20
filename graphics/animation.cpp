#include <chrono>

#include "animation.h"
#include "../util/utils.h"

namespace Graphics {

    // Easing functions.

    /**
     * Show each frame at a fixed interval.
     */
    int linear(long elapsedMs, long durationMs, int frameCount) {
        auto msPerFrame = durationMs / frameCount;
        return elapsedMs / msPerFrame;
    }

    // LIFECYCLE

    /**
     * Constructor
     * Allows you to pass in a custom easing function.
     */
    Animation::Animation(std::vector<Frame*> frames, int durationMs, EasingFunction function) {
        _isStarted = false;

        _frames = frames;
        _durationMs = durationMs;
        _function =  function;
    }

    /**
     * Constructor
     */
    Animation::Animation(std::vector<Frame*> frames, int durationMs, EasingType function) {
        _isStarted = false;

        _frames = frames;
        _durationMs = durationMs;

        switch(function) {
            case EasingType::LINEAR:
            default:
                _function = linear;
        }
    }

    /**
     * Destructor
     */
    Animation::~Animation(void) {
    }



    // METHODS

    /**
     * Start the animation
     */
    void Animation::start(void) {
        _startTime = Util::now();
    }

    /**
     * Gets the frame that should be drawn at this point in the animation.
     * @returns Frame to be rendered.
     */
    const Frame* Animation::getFrame() {
        // Always return the first frame if we haven't started yet.
        if (!_isStarted) {
            return _frames.at(0);
        }

        long elapsed = Util::now() - _startTime;

        // Always show the last frame after the animation has ended.
        if (elapsed > _durationMs) {
            Frame* result = _frames.back();
            return result;
        } else {
            return _frames.at(_function(elapsed, _durationMs, _frames.size()));
        }
    }
}