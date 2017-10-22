#pragma once
#include <SDL2/SDL.h>


/**
 * Class for SDL events management.
 */
class EventManager {
    public:
        // -------------------------------------------------------------------------
        // Body functions
        // -------------------------------------------------------------------------
        void onEvent(SDL_Event* sdlevent);

    public:
        // -------------------------------------------------------------------------
        // Pure virtual functions (To implement in child)
        // -------------------------------------------------------------------------
        virtual void onExit() = 0;
        virtual void onKeyUp(SDL_Keysym) = 0;
        virtual void onKeyDown(SDL_Keysym) = 0;
        virtual void onKeyRight(SDL_Keysym) = 0;
        virtual void onKeyLeft(SDL_Keysym) = 0;
        virtual void onSpace(SDL_Keysym) = 0;
};
