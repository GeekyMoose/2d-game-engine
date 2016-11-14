#pragma once
#include <SDL.h>
#include <vector>

#include "Animation.h"
#include "Surface.h"

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
	~Entity();

public:
	virtual bool loadEntity(const char* file, int w, int h, int nbFrames);
	virtual void doLoop();
	virtual void doRender(SDL_Surface* dest);
	virtual void doCleanup();
};

