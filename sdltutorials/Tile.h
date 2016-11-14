#pragma once

enum {
	TILE_TYPE_NONE = 0,
	TILE_TYPE_NORMAL,
	TILE_TYPE_BLOCK
};

class Tile{
public:
	int tileID; //Unique id of the tile a row of a map
	int typeID; //Type of tile, linked with enum
public:
	Tile();
	~Tile();
};

