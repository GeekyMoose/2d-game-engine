#pragma once

#include "TileType.h"


/**
 * Defines a Tile component.
 * A tile is inside a GameMapArea at a specific position (x,y).
 * It's position is relative to its parent MapArea.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
class Tile {
    private:
        /** X Coordinate of the Tile in MapArea coordinates. */
        const int m_coordinateX;

        /** Y Coordinate of the Tile in MapArea coordinates. */
        const int m_coordinateY;

        /** Type of tile. From enum. */
        const TileType m_tileType;

    public:
        /**
         * Create a new Tile at specific position (x,y) in GameArea.
         *
         * \param x The x coordinate in GameArea.
         * \param y The y coordinate in GameArea.
         * \param type The original tile type
         */
        Tile(const int x, const int y, const TileType type);
};
