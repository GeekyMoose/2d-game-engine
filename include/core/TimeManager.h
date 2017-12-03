#pragma once

#include "utils/platform.h"
#include "utils/Singleton.h"

#include <chrono>


/**
 * Game Time Manager.
 * Manage all game time, such as DeltaTime of the current frame.
 *
 * Use a fixed DeltaTime for the update (For physic engine etc),
 * and a variable delta time for the Render engine.
 *
 * \author  Constantin Masson
 * \date    Oct 2017
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
        void startup() override;
        void shutdown() override;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------
    public:
        /**
         * Update timer data according to the current time.
         * To call at each frame start.
         */
        void update();

        /**
         * Update 
         * If has one, update time data so that, this function may be used
         * in a loop until no fixed frame remain.
         */
        void updateFixedFrame();

        /**
         * Check whether a fixed frame need to be processed.
         *
         * \return True if one more fixed frame, otherwise, returns false.
         */
        bool hasNextFixedFrame();

    public:

        /**
         * Get the DeltaTime value which is in seconds.
         *
         * \return DeltaTime in seconds.
         */
        float getDeltaTime() const;

        /**
         * Get the FixedDeltaTime value.
         *
         * \return FixedDeltaTime in seconds.
         */
        float getFixedDeltaTime() const;
};
