#pragma once

//Type of the tile
enum {
	TILE_TYPE_NONE = 0,
	TILE_TYPE_NORMAL,
	TILE_TYPE_BLOCK
};


/**
 * \brief		Describe a Tile element.
 * \details		A tile the smallest component of a Map
 *
 * \date		Nov 14, 2016
 * \note		Based on SDL Tutorial (http://www.sdltutorials.com/sdl-maps)
 */
class Tile{
public:
	int tileID; //ID of the Frame in sprite-sheet
	int typeID; //Type of tile, linked with enum

public:
	Tile();
};