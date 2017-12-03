#pragma once

#include "utils/platform.h"

#if PLATFORM_WINDOWS
#   include <SDL.h>
#elif PLATFORM_LINUX
#   include <SDL2/SDL.h>
#endif


/**
 * Implements a SDL window.
 *
 * \author  Constantin Masson
 * \date    Oct 2017
 */
class RenderWindowSDL {

    //--------------------------------------------------------------------------
    // Constants - Attributes
    //--------------------------------------------------------------------------
    private:
        SDL_Window*     m_window;   // The famous SDL window
        SDL_Surface*    m_surface;  // Surface from the window


    //--------------------------------------------------------------------------
    // Initialization
    //--------------------------------------------------------------------------
    public:
        RenderWindowSDL();
        ~RenderWindowSDL();


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


    //--------------------------------------------------------------------------
    // SDL Specific methods
    //--------------------------------------------------------------------------
    public:
        SDL_Surface* getSurface();
};


