#pragma once

#include "utils/Platform.h"
#include "utils/Singleton.h"


/**
 * Keep trace of the game FPS.
 */
class FPSManager : private Singleton<FPSManager> {
    private:
        friend Singleton<FPSManager>;
        FPSManager() = default;

    public:
        using Singleton<FPSManager>::getInstance;

    public:
        void startup() override;
        void shutdown() override;

    private:
        float   m_elapsedTimeInSec; // Elapsed time since last average counter
        int     m_currentFPS;       // Current effective FPS
        int     m_frameCounter;     // Current nb of Frame for the average calculation.

    public:
        /**
         * Update the FPS value.
         * To be called at each frame.
         */
        void update();

    public:

        /**
         * Returns the current FPS value.
         *
         * \return Current FPS value.
         */
        int getFPS() const;
};
