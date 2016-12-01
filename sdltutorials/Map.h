#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>

#include "Tile.h"
#include "Surface.h"
#include "constants.h"

#pragma warning(disable:4996) //Allow unsafe fopen / fscanf
#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE //Allow unsafe fopen / fscanf
#endif


/**
 * \brief		Describe a Map element
 * \details		Map is composed by a set of Tiles
 *
 * \date		Nov 14, 2016
 * \note		Based on SDL Tutorial (http://www.sdltutorials.com/sdl-maps)
 */
class Map{
	//--------------------------------------------------------------------------
	// Constants - Attributes
	//--------------------------------------------------------------------------
public:
	SDL_Surface* tilesSprites; //Pointer to the tiles sprite-sheet for this map
private:
	std::vector<Tile> listTiles; //All loaded tiles for this map

public:
	//--------------------------------------------------------------------------
	// Constructors
	//--------------------------------------------------------------------------
	Map();

public:
	//--------------------------------------------------------------------------
	// Corps functions
	//--------------------------------------------------------------------------

	/**
	 * \brief			Load a Map using file save.
	 * \warning			Unsafe result if invalid file format or data.
	 * 
	 * \param file		File to load (Path + name + extension).
	 * \return			True if loaded successfully, otherwise, return false.
	 */
	bool loadMap(const char* file);

	/**
	 * \brief			Render map on a surface.
	 * \warning			Map must have been loaded successfully otherwise, do nothing.
	 * 
	 * \param dest		SDL_Surface destination where to render map.
	 * \param mapX		X coordinate where to draw map on the dest.
	 * \param mapY		Y coordinate where to draw map on the dest.
	 */
	void renderMap(SDL_Surface* dest, int mapX, int mapY);
};

