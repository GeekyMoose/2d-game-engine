#pragma once

#include "utils/Platform.h"
#include "utils/Singleton.h"
#include "core/TimeManager.h"
#include "core/FPSManager.h"
#include "input/InputManager.h"
#include "sdl/AppWindowSDL2.h"


/**
 * The main 2D engine component.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
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
        bool            m_isRunning;
        TimeManager&    m_timeManager;
        FPSManager&     m_fpsManager;
        InputManager&   m_inputManager;
        AppWindowSDL2   m_window;


    // -------------------------------------------------------------------------
    // Init
    // -------------------------------------------------------------------------
    private:
        Engine2D();
        ~Engine2D();

    public:
        void startup() override;
        void shutdown() override;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------
    public:

        /**
         * Start the engine.
         */
        void run();
};
