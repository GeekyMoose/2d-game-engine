#pragma once
#include <SDL.h>
#include <SDL_image.h>


/**
 * \brief		Asset function to draw SDL surface on another surface
 * \details		Set of static functions
 */
class Surface{
public:
	Surface();

public:
	static SDL_Surface* doLoad(const char* file);
	static bool doDraw(SDL_Surface* src, SDL_Surface* dest, int x, int y);
	static bool doDraw(SDL_Surface* src, int x, int y, int w, int h, SDL_Surface* dest, int x2, int y2);
	static bool transparent(SDL_Surface* dest, int r, int g, int b);
};