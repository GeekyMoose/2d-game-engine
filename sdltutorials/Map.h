#pragma once
#include <SDL.h>
#include <vector>

#include "Tile.h"
#include "Surface.h"
#include "constants.h"

#pragma warning(disable:4996) //Allow unsafe fopen / fscanf
#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE //Allow unsafe fopen / fscanf
#endif


class Map{
public:
	SDL_Surface* tilesSprites;
private:
	std::vector<Tile> listTiles;

public:
	Map();
	~Map();

public:
	bool loadMap(const char* file);
	void renderMap(SDL_Surface* dest, int mapX, int mapY);
};

