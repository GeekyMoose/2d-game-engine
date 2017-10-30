#pragma once

#include "helper/Platform.h"

#include "core/Area.h"
#include "core/Camera.h"
#include "gameplay/Entity.h"
#include "gameplay/Player.h"
#include "helper/Logger.h"
#include "sdl/AppWindowSDL2.h"
#include "sdl/Surface.h"


/**
 * SDL application.
 *
 * \warning
 * Deprecated
 */
class App {

    //--------------------------------------------------------------------------
    // Constants - Attributes
    //--------------------------------------------------------------------------
    private:
        bool isRunning;
        AppWindowSDL2 m_window;

        Player player1;


    //--------------------------------------------------------------------------
    // Constructors - Destructor
    //--------------------------------------------------------------------------
    public:
        App();


    //--------------------------------------------------------------------------
    // Body function (Initialization - Stop)
    //--------------------------------------------------------------------------
    public:

        /**
         * Start running the application.
         * Must be not running already.
         * This function will block till SDL exit.
         * Call init, then loop till end, then call cleanup.
         *
         * \return -1 if error, otherwise, return 0.
         */
        int executeApp();

    private:

        /**
         * Initialize SDL and all elements for the application.
         * Do nothing if already running and return false.
         * Load SDL module, return false if unable.
         *
         * \return True if successfully init, otherwise, return false.
         */
        bool initApp();

        /**
         * Clean up all loaded memory and quit SDL.
         */
        void doCleanup();

    //--------------------------------------------------------------------------
    // Body function (Execution)
    //--------------------------------------------------------------------------
    private:
        void doEvent(SDL_Event* sdlevent);
        void doLoop();
        void doRender();
};
