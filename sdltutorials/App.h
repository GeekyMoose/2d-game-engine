#pragma once

#include <iostream>
#include <ostream>
#include <SDL.h>

#include "EventManager.h"
#include "Animation.h"
#include "Surface.h"

#define WINDOWS_TITLE "sdltutorials"

class App : public EventManager{
private:
	bool isRunning;
	int screen_width;
	int screen_height;
	SDL_Window* window;
	SDL_Surface* screen;
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