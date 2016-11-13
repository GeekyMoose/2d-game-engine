#pragma once
#include <SDL.h>

class Animation{
private:
	int currentFrame;
	int nbFrames; // Total nb of frame in animation
	int animSpeed; //In milliseconds
	int oldTime;

public:
	int nextFrame;
	int oscillate;


public:
	Animation();
	~Animation();

	void doAnimate();

public:
	int getCurrentFrame();
	void setNbFrames(int nbFrames);
	void setCurrentFrame(int frame);
	void setAnimSpeed(int speed);
};

