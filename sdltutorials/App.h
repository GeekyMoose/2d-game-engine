#pragma once

#include <iostream>
#include <ostream>
#include <SDL.h>

#include "EventManager.h"
#include "Surface.h"
#include "Entity.h"
#include "constants.h"
#include "Area.h"
#include "Camera.h"


/**
 * \brief	Define an SDL application
 *
 * \date	Nov 14, 2016
 * \note	Based on SDL Tutorial (http://www.sdltutorials.com/sdl-tutorial-basics)
 */
class App : public EventManager{
private:
	//--------------------------------------------------------------------------
	// Constants - Attributes
	//--------------------------------------------------------------------------
	bool isRunning;
	SDL_Window* window; //SDL main windows
	SDL_Surface* screen; //Surface from the windows

	Entity entity1; //TODO TMP for test

public:
	//--------------------------------------------------------------------------
	// Constructors - Destructor
	//--------------------------------------------------------------------------
	App();
	~App();

public:
	//--------------------------------------------------------------------------
	// Body function (Initialization - Stop)
	//--------------------------------------------------------------------------

	/**
	 * \brief			Start running the application.
	 * \details			Must be not running already.
	 *					This function will block till SDL exit.
	 *					Call init, then loop till end, then call cleanup.
	 * 
	 * \return			-1 if error, otherwise, return 0.
	 */
	int executeApp();

private:
	/**
	 * \brief			Initialize SDL and all elements for the application.
	 * \details			Do nothing if already running and return false.
	 *					Load SDL module, return false if unable.
	 *
	 * \return			True if successfully init, otherwise, return false.
	 */
	bool initApp();

	/**
	 * \brief			Clean up all loaded memory and quit SDL.
	 *
	 */
	void doCleanup();

	//--------------------------------------------------------------------------
	// Body function (Execution)
	//--------------------------------------------------------------------------
	void doEvent(SDL_Event* sdlevent);
	void doLoop();
	void doRender();

public:
	//--------------------------------------------------------------------------
	// Override function (EventManager)
	//--------------------------------------------------------------------------
	void onKeyDown(SDL_Keysym keysym);
	void onExit();
};