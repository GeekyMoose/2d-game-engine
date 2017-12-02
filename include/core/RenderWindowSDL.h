#pragma once

#include "utils/Platform.h"

#if PLATFORM_WINDOWS
#   include <SDL.h>
#elif PLATFORM_LINUX
#   include <SDL2/SDL.h>
#endif


/**
 * Render a Window using SDL2 
 *
 * \author  Constantin Masson
 * \date    Oct 2017
 */
class RenderWindowSDL {

    //--------------------------------------------------------------------------
    // Constants - Attributes
    //--------------------------------------------------------------------------
    private:
        SDL_Window*     m_SDLwindow;    // The famous SDL window
        SDL_Surface*    m_SDLsurface;   // Surface from the window


    //--------------------------------------------------------------------------
    // Initialization
    //--------------------------------------------------------------------------
    public:
        RenderWindowSDL() = default;
        ~RenderWindowSDL();

        /**
         * Initialize all data for this window.
         * Window is ready to be displayed.
         */
        void initialize();

        /**
         * Destroy this window.
         * Free all resources and delete the window.
         */
        void destroy();


    //--------------------------------------------------------------------------
    // Other methods
    //--------------------------------------------------------------------------
    public:
        void show();
        void hide();
        void maximize();
        void minimize();

    public:
        void update();
        void clear();

};

