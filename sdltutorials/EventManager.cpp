#include "EventManager.h"

EventManager::EventManager(){
}

EventManager::~EventManager(){
}

void EventManager::onEvent(SDL_Event * sdlevent){
	switch(sdlevent->type){
		case SDL_QUIT:
			onExit();
			break;
		default:
			break;
	}
}

void EventManager::onExit(){}