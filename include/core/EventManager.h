#pragma once

#include "helper/Platform.h"


/**
 * Class for SDL events management.
 */
class EventManager {
    // -------------------------------------------------------------------------
    // Body functions
    // -------------------------------------------------------------------------
    public:
        void onEvent(SDL_Event* sdlevent);


    // -------------------------------------------------------------------------
    // Pure virtual functions (To implement in child)
    // -------------------------------------------------------------------------
    public:
        virtual void onExit() = 0;
        virtual void onKeyUp(SDL_Keysym) = 0;
        virtual void onKeyDown(SDL_Keysym) = 0;
        virtual void onKeyRight(SDL_Keysym) = 0;
        virtual void onKeyLeft(SDL_Keysym) = 0;
        virtual void onSpace(SDL_Keysym) = 0;
};
