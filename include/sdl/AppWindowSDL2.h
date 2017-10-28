#pragma once

#include "helper/Platform.h"

#if PLATFORM_WINDOWS
#   include <SDL.h>
#elif PLATFORM_LINUX
#   include <SDL2/SDL.h>
#endif


/**
 * Render a Window using SDL2 
 *
 * \author Constantin Masson
 */
class AppWindowSDL2 {

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
        AppWindowSDL2() = default;
        ~AppWindowSDL2();

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


    //--------------------------------------------------------------------------
    // Getter / Setters
    //--------------------------------------------------------------------------
    public:

        /**
         * Returns the pointer to the current window's SDL surface.
         *
         * \return The surface used by this window.
         */
        SDL_Surface* getSurface() const;

        /**
         * Returns the Root element of this window.
         * In this case, root element is a SDLWindow object.
         *
         * \return The SDLWindow object pointer.
         */
        SDL_Window* getRoot() const;
};

