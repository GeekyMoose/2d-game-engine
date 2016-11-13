#pragma once
#include <SDL.h>

class Surface{
public:
	Surface();
	~Surface();

public:
	static SDL_Surface* doLoad(const char* file);
	static bool doDraw(SDL_Surface* src, SDL_Surface* dest, int x, int y);
	static bool doDraw(SDL_Surface* src, int x, int y, SDL_Surface* dest, int x2, int y2);
};

