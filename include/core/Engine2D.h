#pragma once

#include "helper/Singleton.h"

#include <chrono>


/**
 * The main 2D engine component.
 */
class Engine2D : private Singleton<Engine2D> {
    // -------------------------------------------------------------------------
    // Attributes
    // -------------------------------------------------------------------------
    private:
        friend Singleton<Engine2D>; // For singleton use
        bool isRunning;

    public:
        using Singleton<Engine2D>::getInstance;


    // -------------------------------------------------------------------------
    // Init
    // -------------------------------------------------------------------------
    private:
        Engine2D() = default;

    public:
        void startUp() override;
        void shutDown() override;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------
    public:
        void run();
};
