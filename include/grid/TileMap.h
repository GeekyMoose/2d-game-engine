#pragma once

#include "utils/platform.h"
#include "utils/gameConfig.h"
#include "Tile.h"

class Camera;
class SDL_Surface;


/**
 * Defines a tilemap.
 * TileMap is a two dimensions array of Tiles.
 *
 * \date    Dec 2017
 * \author  Constantin Masson
 */
class TileMap {
    private:
        const int m_tilesPerRow     = TILEMAP_SIZE_COL;
        const int m_tilesPerColumn  = TILEMAP_SIZE_ROW;
        Tile m_tiles[TILEMAP_SIZE_COL][TILEMAP_SIZE_ROW];

    public:
        TileMap() = default;
        ~TileMap() = default;

    public:
        /**
         * Load TileMap content from file.
         *
         * \warning
         * Undefined behavior in case of wrong file format or invalid data.
         *
         * \param file  File to use (Whole path + name + extension).
         * \return      True if successfully loaded, otherwise, return false.
         */
        bool loadFromFile(const char* file);

        void render(SDL_Surface* dest, const Camera* cctv, const int width, const int height);
};
