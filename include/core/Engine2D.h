#pragma once

#include "helper/Platform.h"
#include "helper/Singleton.h"
#include "core/TimeManager.h"


/**
 * The main 2D engine component.
 */
class Engine2D : private Singleton<Engine2D> {
    // -------------------------------------------------------------------------
    // Attributes
    // -------------------------------------------------------------------------
    private:
        friend Singleton<Engine2D>; // For singleton use
    public:
        using Singleton<Engine2D>::getInstance;

    private:
        bool m_isRunning;
        TimeManager& timeManager;


    // -------------------------------------------------------------------------
    // Init
    // -------------------------------------------------------------------------
    private:
        Engine2D();
        ~Engine2D();

    public:
        void startUp() override;
        void shutDown() override;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------
    public:
        void run();
};
