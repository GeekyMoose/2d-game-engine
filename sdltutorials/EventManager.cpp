#include "EventManager.h"

void EventManager::onEvent(SDL_Event* sdlevent){
	switch(sdlevent->type){
		case SDL_KEYDOWN:
			onKeyDown(sdlevent->key.keysym);
			break;
		case SDL_QUIT:
			onExit();
			break;
		default:
			break;
	}
}