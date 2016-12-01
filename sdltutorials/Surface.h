#pragma once
#include <SDL.h>
#include <SDL_image.h>


/**
 * \brief		Asset function to draw SDL surface on another surface.
 * \details		Set of static functions.
 *
 * \note		Based on SDL Tutorial (http://www.sdltutorials.com/sdl-coordinates-and-blitting).
 */
class Surface{

public:
	/**
	 * \brief		Load a SDL_Surface from its path.
	 *
	 * \param file	File to load (path + name + extension).
	 * \return		The SDL_Surface.
	 */
	static SDL_Surface* doLoad(const char* file);

	/**
	 * \brief		Draw SDL_Surface on another SDL_Surface.
	 * \warning		If any NULL surface given, do nothing.
	 *
	 * \param src	SDL_Surface to draw (Must be not null).
	 * \param dest	SDL_Surface where to draw (Must be not null).
	 * \param x		X position where to place src in dest.
	 * \param y		Y position where to place src in dest.
	 * \return		True if successfully drawn, otherwise, return fase.
	 */
	static bool doDraw(SDL_Surface* src, SDL_Surface* dest, int x, int y);

	/**
	 * \brief		Draw SDL_Surface on another SDL_Surface.
	 * \warning		If any NULL surface given, do nothing.
	 *
	 * \param src	SDL_Surface to draw (Must be not null).
	 * \param x		Get SDL_Surface starting at position x in src.
	 * \param y		Get SDL_Surface starting at position y in src.
	 * \param w		Width to get in src (Final recovered part is from x to x+w).
	 * \param h		Height to get in src (Final recovered part is from y to y+h).
	 * \param dest	SDL_Surface where to draw (Must be not null).
	 * \param x2	X position where to place src in dest.
	 * \param y2	Y position where to place src in dest.
	 * \return		True if successfully drawn, otherwise, return fase.
	 */
	static bool doDraw(SDL_Surface* src, int x, int y, int w, int h, SDL_Surface* dest, int x2, int y2);

	/**
	 * \brief		Set a color as transparent in SDL_Surface.
	 * \warning		If NULL given, do nothing. The given RGB color won't be visible anymore
	 *
	 * \param dest	SDL_Surface to apply transparency.
	 * \param r		Red value.
	 * \param g		Green value.
	 * \param b		Blue value.
	 * \return		True if transparency successfully applied, otherwise, return false.
	 */
	static bool transparent(SDL_Surface* dest, int r, int g, int b);
};