#pragma once

#include "helper/Platform.h"
#include "helper/Singleton.h"


/**
 * Keep trace of the game FPS.
 */
class FPS : private Singleton<FPS> {
    private:
        friend Singleton<FPS>;
        FPS() = default;
    public:
        using Singleton<FPS>::getInstance;

    public:
        void startUp() override;
        void shutDown() override;

    private:
        float m_elapsedTimeInSec; // Elapsed time since last average counter
        int m_currentFPS; // Current effective FPS
        int m_frameCounter; // Current nb of Frame for the average calculation.

    public:
        void update();

    public:
        int getFPS() const;
};
