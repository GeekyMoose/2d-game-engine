#pragma once

#include "gamemap/Tile.h"
#include "helper/gameConfig.h"


/**
 * SubComponent of a GameMap.
 * MapArea is made of Tiles.
 *
 * \date    Nov 2017
 * \author  Constantin Masson
 */
class MapArea {
    // -------------------------------------------------------------------------
    // Attributes
    // -------------------------------------------------------------------------
    private:
        /** X Position of the Area inside its GameMap parent. */
        const int m_coordinateX;

        /** Y Position of the Area inside its GameMap parent. */
        const int m_coordinateY;

        /** Matrix of tiles. */
        Tile* m_tiles[GameMapData::AREA_NB_TILES_ROW][GameMapData::AREA_NB_TILES_COL];


    // -------------------------------------------------------------------------
    // Init
    // -------------------------------------------------------------------------
    private:
        /**
         * Create a new MapArea placed in specific GameMap position.
         *
         * \param x The X coordinate in GameMap.
         * \param y The Y coordinate in GameMap.
         */
        MapArea(const int x, const int y);

        ~MapArea() = default;

    public:

        /**
         * Load a MapArea from the given file.
         *
         * \param file File to use (Whole path + name + extension).
         * \return True if successfully loaded, otherwise, return false.
         */
        static bool loadFromFile(const char* file);
};
