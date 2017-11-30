#pragma once

#include "utils/Platform.h"
#include "utils/Singleton.h"
#include "core/TimeManager.h"
#include "core/FPSManager.h"
#include "core/GameManager.h"
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
        GameManager&    m_gameManager;
        AppWindowSDL2   m_window;


    // -------------------------------------------------------------------------
    // Init
    // -------------------------------------------------------------------------
    private:
        Engine2D();
        ~Engine2D();

    public:
        /**
         * override from Singleton.
         * Startup the engine.
         * This only initialize the engine but does not start running it.
         * All subcomponents area initialized.
         *
         * \warning
         * Not thread safe, do not call it twice.
         */
        void startup() override;

        /**
         * override from Singleton.
         * Shutdown the engine.
         * All subcomponents area stopped and freed.
         */
        void shutdown() override;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------
    public:

        /**
         * Start the engine.
         * Do nothing if engine is not startup.
         *
         * \warning
         * Not thread safe, do not call it twice. (Undefined behavior).
         */
        void run();
};
