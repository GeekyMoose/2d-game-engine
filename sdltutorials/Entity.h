#pragma once
#include <SDL.h>
#include <vector>

#include "Animation.h"
#include "Surface.h"


/**
 * \brief		Define an Entity.
 * \details		Entity is anything we can interact with. (Almost anything that moves)
 *
 * \date		Nov 14, 2016
 * \note		Based on SDL Tutorial (http://www.sdltutorials.com/sdl-entities)
 *
 */
class Entity{
public:
	static std::vector<Entity*> listEntities;
protected:
	Animation animEntity;
	SDL_Surface* surfaceEntity;
public:
	float x;
	float y;
	int width;
	int height;

public:
	Entity();

public:

	/**
	 * \brief			Load entity from file
	 * \details			A transparent color is automatically applied on pink (255,0,255)
	 *
	 * \param file		File to load (path + filename + extension)
	 * \param w			Width of the entity (Pixels)
	 * \param h			Height of the entity (Pixels)
	 * \param nbFrames	Define how many image draw this entity (used for animation)
	 */
	virtual bool loadEntity(const char* file, int w, int h, int nbFrames);

	/**
	 * \brief			Define action to do at each loop
	 */
	virtual void doLoop();

	/**
	 * \brief			Draw entity on given surface
	 *
	 * \param dest		SDL_Surface where to draw entity
	 */
	virtual void doRender(SDL_Surface* dest);

	/**
	 * \brief			Cleanup entity
	 * \details			Entity mustn't be used till another load
	 */
	virtual void doCleanup();
};

