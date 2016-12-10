#pragma once
#include <SDL.h>

class FPS{
public:
	static FPS FPSControl; //Singleton

private:
	int oldTime; //To calculate FPS
	int lastTime; //To calculate speed factor
	float speedFactor; //Current speed factor of the game (Usually inf to 1)
	int nbFrames; //Game current FPS
	int fpsCounter; //Frame count for FPS

public:
	FPS();

	void onLoop();

public:
	int getFPS();
	float getSpeedFactor();
};