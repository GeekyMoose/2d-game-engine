#pragma once

#include "utils/platform.h"
#include "utils/Singleton.h"
#include "core/TimeManager.h"
#include "core/FPSManager.h"
#include "core/SceneManager.h"
#include "core/RenderEngine.h"
#include "core/RenderWindowSDL.h"
#include "core/TextureManager.h"
#include "core/SpriteManager.h"
#include "grid/GridManager.h"
#include "input/InputManager.h"


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
        bool                m_isRunning;

        TimeManager&        m_timeManager;
        FPSManager&         m_fpsManager;
        InputManager&       m_inputManager;
        TextureManager&     m_textureManager;
        SpriteManager&      m_spriteManager;
        SceneManager&       m_sceneManager;
        RenderEngine&       m_renderEngine;
        GridManager&        m_gridManager;

        RenderWindowSDL*    m_window;


    // Things for singleton
    private:
        friend Singleton<Engine2D>;
    public:
        using Singleton<Engine2D>::getInstance;


    // -------------------------------------------------------------------------
    // Init
    // -------------------------------------------------------------------------
    private:
        Engine2D();
        ~Engine2D();

    public:
        /**
         * Startup the engine.
         * This only initialize the engine but does not start running it.
         * All subcomponents area initialized.
         *
         * \warning
         * Not thread safe, do not call it twice.
         */
        void startup() override;

        /**
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
         * Do nothing if engine is not already startup.
         *
         * \warning
         * Not thread safe, do not call it twice. (Undefined behavior).
         */
        void run();
};
