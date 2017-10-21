#pragma once

//Type of the tile
enum {
    TILE_TYPE_NONE = 0,
    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK
};


/**
 * Describe a Tile element.
 * A tile the smallest component of a Map
 */
class Tile {
    public:
        int tileID; //ID of the Frame in sprite-sheet
        int typeID; //Type of tile, linked with enum

    public:
        Tile();
};
