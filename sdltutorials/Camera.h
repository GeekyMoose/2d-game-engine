#pragma once
#include <SDL.h>

#include "constants.h"


enum{
	TARGET_MODE_NORMAL = 0, //Position to the top left of the target
	TARGET_MODE_CENTER //Center camera to the target
};


class Camera{
	//--------------------------------------------------------------------------
	// Attributes
	//--------------------------------------------------------------------------
public:
	static Camera cameraControl; //To access camera from anywhere
private:
	int x; //Camera position (in pixel)
	int y;
	int* targetX; //To target an element (Null if not target)
	int* targetY;
public:
	int targetMode;

public:
	//--------------------------------------------------------------------------
	// Constructors
	//--------------------------------------------------------------------------
	Camera();

	//--------------------------------------------------------------------------
	// Body functions
	//--------------------------------------------------------------------------

	/**
	 * \brief Move the camera
	 * 
	 * \param moveX X coordinate translation
	 * \param moveY Y coordinate translation
	 */
	void moveCamera(int moveX, int moveY);

	/**
	 * \brief Return X camera position
	 * \details The returned value depend if a target is set and use the camera mode.
	 *
	 * \return Current X coordinate
	 */
	int getX();

	/**
	* \brief Return Y camera position
	* \details The returned value depend if a target is set and use the camera mode.
	*
	* \return Current Y coordinate
	*/
	int getY();

	void setPosition(int posX, int posY);
	void setTarget(int* posX, int* posY);
};

