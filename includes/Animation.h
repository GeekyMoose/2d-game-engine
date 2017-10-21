#pragma once
#include <SDL2/SDL.h>


/**
 * \brief	Manage animation
 *
 * \date	Nov 14, 2016
 * \note	Base on SDL Tutorial (http://www.sdltutorials.com/sdl-animation)
 */
class Animation{
private:
	int currentFrame;
	int nbFrames; // Total nb of frame in animation
	int animSpeed; //In milliseconds, time between to frames
	int oldTime; //Time when last change was done

public:
	int nextFrame; //Define the distance to next frame (usually 1 or -1)
	int oscillate; //If not oscillate, go back to 0 when reach last frame


public:
	Animation();

	/**
	* \brief Process animation, currentFrame change condition reached
	*
	* Check the difference between currentTime and oldTime (Gives delta time). 
	* If animSpeed is higher than this value, animation change.
	*/
	void doAnimate();

public:
	int getCurrentFrame();
	void setNbFrames(int nbFrames);
	void setCurrentFrame(int frame);
	void setAnimSpeed(int speed);
};

