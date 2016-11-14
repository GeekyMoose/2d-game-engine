#pragma once

#include <iostream>
#include <ostream>
#include <SDL.h>

#include "EventManager.h"
#include "Surface.h"
#include "Entity.h"
#include "constants.h"

class App : public EventManager{
private:
	bool isRunning;
	int screen_width;
	int screen_height;
	SDL_Window* window;
	SDL_Surface* screen;

	Entity entity1; //TMP for test
public:
	App();
	~App();

	int executeApp();

public:
	bool initApp();
	void doEvent(SDL_Event* sdlevent);
	void doLoop();
	void doRender();
	void doCleanup();

public:
	void onExit();
};