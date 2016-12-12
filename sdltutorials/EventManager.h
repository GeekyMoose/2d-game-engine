#pragma once
#include <SDL.h>

/**
 * \brief	Class for SDL events management
 *
 * \date	Nov 14, 2016
 * \note	Based on SDL Tutorial (http://www.sdltutorials.com/sdl-events)
 */
class EventManager{
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
};