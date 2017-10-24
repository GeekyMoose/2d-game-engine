#pragma once

#include "helper/Singleton.h"

#include <chrono>


/**
 * Game Time Manager.
 * Manage all game time, such as DeltaTime of the current frame.
 *
 * Use a fixed DeltaTime for the update (For physic engine etc),
 * and a variable delta time for the Render engine.
 */
class TimeManager : private Singleton<TimeManager> {
    // -------------------------------------------------------------------------
    // Attributes
    // -------------------------------------------------------------------------
    private:
        friend Singleton<TimeManager>;
    public:
        using Singleton<TimeManager>::getInstance;


    private:
        /** DeltaTime in seconds. */
        float m_deltaTime;

    private:
        /** Keep trace when the current frame started. */
        std::chrono::time_point<std::chrono::steady_clock> m_currentStartTime;

        /** Fixed deltaTime in seconds used by update (Physic etc) */
        float m_fixedUpdateTimeInSec;

        /** Internally used by fixed update */
        float m_leftOverFixedTime;


    // -------------------------------------------------------------------------
    // Initialization
    // -------------------------------------------------------------------------
    private:
        TimeManager() = default;
        ~TimeManager() = default;

    public:
        void startUp() override;
        void shutDown() override;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------
    public:
        /**
         * Update timer data according to the current time.
         * To call at each frame start.
         */
        void updateTimer();

        /**
         * Check whether a fixed frame need to be processed.
         * If has one, update time data so that, this function may be used
         * in a loop until no fixed frame remain.
         *
         * \return True if has one fixed frame to process, otherwise, return false.
         */
        bool hasNextFixedFrame();

    public:
        float getDeltaTime() const;
        float getFixedDeltaTime() const;
};
