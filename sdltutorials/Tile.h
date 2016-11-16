#pragma once

enum {
	TILE_TYPE_NONE = 0,
	TILE_TYPE_NORMAL,
	TILE_TYPE_BLOCK
};


/**
 *
 * \date Nov 14, 2016
 *
 * \brief Describe a Tile element.
 * \details A tile the smallest component of a Map
 *
 */
class Tile{
public:
	int tileID; //Id of the tile (For link with spritesheet position)
	int typeID; //Type of tile, linked with enum

public:
	Tile();
	~Tile();
};

