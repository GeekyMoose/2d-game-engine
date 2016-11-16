#pragma once
#include <SDL.h>

/**
 *
 * \date Nov 14, 2016
 *
 * \brief Class for SDL events management
 *
 */
class EventManager{
public:
	// -------------------------------------------------------------------------
	// Constructors - Destructors
	// -------------------------------------------------------------------------
	EventManager();
	~EventManager();

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
	virtual void onKeyDown(SDL_Keysym) = 0;
};