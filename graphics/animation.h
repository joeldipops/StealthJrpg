#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <vector>
#include <ctime>

#include "../res/sprites.h"
#include "frame.h"

namespace Graphics {
    /**
     * 
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
            Animation(std::vector<Frame*> frames, int durationMs, EasingType function);
            Animation(std::vector<Frame*> frames, int durationMs, EasingFunction function);
            void start(void);
            const Frame* getFrame();
        protected:
            ~Animation(void);
        private:
            std::vector<Frame*> _frames;
            EasingFunction _function;
            int _durationMs;
            long _startTime;
            bool _isStarted;
    };

}

#endif