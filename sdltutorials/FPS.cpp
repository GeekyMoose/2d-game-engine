#include "FPS.h"

FPS FPS::FPSControl;

FPS::FPS(){
	oldTime		= 0;
	lastTime	= 0;
	speedFactor = 0;
	nbFrames	= 0;
	fpsCounter	= 0;
}

void FPS::onLoop(){
	//If one second since last refresh, update fps data
	if(oldTime+1000>SDL_GetTicks()){
		oldTime		= SDL_GetTicks();
		nbFrames	= fpsCounter;
		fpsCounter	= 0;
	}
	//Update speedFactor and frames.
	//32 represents the nb of pixel to move in 1 second (Default general speed)
	speedFactor = ((SDL_GetTicks()-lastTime)/1000.0f)*32.0f;
	lastTime	= SDL_GetTicks();
	fpsCounter++;
}

int FPS::getFPS(){
	return nbFrames;
}

float FPS::getSpeedFactor(){
	return speedFactor;
}