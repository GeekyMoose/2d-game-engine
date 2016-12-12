#pragma once
#include "Entity.h"

class Player : public Entity{
public:
	Player();
	bool loadEntity(const char* file, int w, int h, int nbFrames);
	void doLoop();
	void doRender(SDL_Surface* dest);
	void doCleanup();
	void doAnimate();
	void doCollision(Entity* other);
};