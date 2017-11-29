#pragma once

#include "gamemap/Tile.h"
#include "utils/gameConfig.h"
#include "sdl/Surface.h"


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
    public:
        MapArea() = default;
        ~MapArea() = default;

    public:

        /**
         * Load a MapArea from the given file.
         *
         * \warning
         * Undefined behavior in case of wrong file format.
         *
         * \param file  File to use (Whole path + name + extension).
         * \return      True if successfully loaded, otherwise, return false.
         */
        bool loadFromFile(const char* file);

        /**
         * Render this area on a surface.
         * Area must have been loaded successfully otherwise, do nothing.
         *
         * \param dest  Surface destination where to render map.
         * \param mapX  X coordinate where to draw area on the dest.
         * \param mapY  Y coordinate where to draw area on the dest.
         */
        void render(SDL_Surface* dest, const int destX, const int destY);


    //--------------------------------------------------------------------------
    // Getters - Setters
    //--------------------------------------------------------------------------
    public:

        /**
         * Returns the tile under pixel (x,y) or null.
         *
         * \note
         * Origin (0,0) is the upper-left corner of this Area.
         *
         * \param posX  X position in pixel.
         * \param posY  Y position in pixel.
         * \return      The tile or nullptr if no tile.
         */
        Tile* getTile(const int posX, const int posY);
};
