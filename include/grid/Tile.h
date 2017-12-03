#pragma once

#include "utils/platform.h"
#include "utils/SDLHelper.h"
#include "TileType.h"

class SDL_Surface;
class Sprite;


/**
 * Defines a Tile component.
 * A tile is the smallest unit of a TileMap.
 * It is placed in a specific TileMap coordinates.
 *
 * \author  Constantin Masson
 * \date    Oct 2017
 */
class Tile {
    private:
        /** Type of tile. From enum. */
        int m_tileType = 0;

        /** Sprite this tile use for rendering. */
        Sprite* m_sprite = nullptr;

    public:
        Tile() = default;
        ~Tile() = default;

        /**
         * Render a tile on a surface.
         * Draw the Tile on the surface at given destination coordinates.
         * Coordinates are the Tile upper-left-corner.
         *
         * \param dest Surface where to render.
         * \param destX Tile X coordinate on the surface.
         * \param destY Tile Y coordinate on the surface.
         */
        void render(SDL_Surface* dest, const int destX, const int destY);


    // -------------------------------------------------------------------------
    // Getters - Setters
    // -------------------------------------------------------------------------
    public:
        void setType(const int type);
        int getType() const;
};


