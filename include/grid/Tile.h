#pragma once

#include "utils/platform.h"
#include "utils/SDLHelper.h"
#include "TileType.h"


/**
 * Defines a Tile component.
 * A tile is inside a GameMapArea at a specific position (x,y).
 * It's position is relative to its parent MapArea.
 *
 * \author  Constantin Masson
 * \date    Oct 2017
 */
class Tile {
    private:
        /** X Coordinate of the Tile in MapArea coordinates. */
        const int m_coordinateX;

        /** Y Coordinate of the Tile in MapArea coordinates. */
        const int m_coordinateY;

        /** Type of tile. From enum. */
        const int m_tileType;

        /** Name of the resource for this tile. (Resource is the Sprite). */
        const char* resource;

    public:
        /**
         * Create a new Tile at specific position (x,y) in GameArea.
         *
         * \param x The x coordinate in GameArea.
         * \param y The y coordinate in GameArea.
         * \param type The original tile type
         */
        Tile(const int x, const int y, const int type);

        /**
         * Render a tile on a surface.
         * Coordinates are upper-left-corner of the tile in the destination.
         *
         * \param dest Surface where to render.
         * \param destX Coordinate X of upper-left-corner in dest.
         * \param destY Coordinate Y of upper-left-corner in dest.
         */
        void render(SDL_Surface* dest, const int destX, const int destY);
};


