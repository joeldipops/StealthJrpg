#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <vector>
#include <ctime>

#include "../res/sprites.h"
#include "frame.h"

namespace Graphics {
    /**
     * Function to select the current animation frame based on time since animation began.
     * @param elapsedMs How long the animation has been playing so far.
     * @param durationMs Total time animation should play for.
     * @param frameCount Total number of frames in the animation.
     * @returns The frame currently to be shown.
     */
    typedef int (*EasingFunction)(long elapsedMs, long durationMs, int frameCount);

    enum EasingType {
        LINEAR,
        EASED,
        EASE_IN,
        EASE_OUT,
        INVERSE_EASE
    };

    class Animation {
        public:
            Animation(std::vector<Frame*> frames, EasingType function);
            Animation(std::vector<Frame*> frames, EasingFunction function);
            ~Animation(void);
            void start(int durationMs);
            const Frame* getFrame();

        private:
            std::vector<Frame*> _frames = {};
            EasingFunction _function;
            long _startTime = 0;
            bool _isStarted = false;
            int _durationMs = 0;
    };

}

#endif