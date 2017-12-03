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
        /** Type of tile. From enum. */
        int m_tileType = 0;

        /** Name of the resource for this tile. (Resource is the Sprite). */
        const char* resource;

    public:
        Tile() = default;
        ~Tile() = default;

        /**
         * Render a tile on a surface.
         * Coordinates are upper-left-corner of the tile in the destination.
         *
         * \param dest Surface where to render.
         * \param destX Coordinate X of upper-left-corner in dest.
         * \param destY Coordinate Y of upper-left-corner in dest.
         */
        void render(SDL_Surface* dest, const int destX, const int destY);


    // -------------------------------------------------------------------------
    // Getters - Setters
    // -------------------------------------------------------------------------
    public:
        void setType(const int type);
        int getType() const;
};


