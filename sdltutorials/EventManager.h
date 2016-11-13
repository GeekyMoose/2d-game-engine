#pragma once
#include <SDL.h>

class EventManager{
public:
	EventManager();
	~EventManager();

public:
	virtual void onEvent(SDL_Event* sdlevent);

public:
	virtual void onExit();
};

