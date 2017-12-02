#pragma once

#include "MapArea.h"
#include "core/Camera.h"
#include "utils/Platform.h"
#include "utils/gameConfig.h"
#include "utils/SDLHelper.h"


/**
 * GameMap.
 * A GameMap is the game world.
 * A GameMap is composed of GameMapAreas.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
class GameMap {
    private:
        /** All area in this map. */
        MapArea m_areas[MAP_SIZE_ROW][MAP_SIZE_COL];


    // -------------------------------------------------------------------------
    // Init
    // -------------------------------------------------------------------------
    public:
        GameMap() = default;
        ~GameMap() = default;

    public:

        /**
         * Load a GameMap from the given file.
         *
         * \warning
         * Undefined behavior in case of wrong file format.
         * (May be security issue).
         *
         * \param file  File to use (Whole path + name + extension).
         * \return      True if successfully loaded, otherwise, return false.
         */
        bool loadFromFile(const char* file);


    // -------------------------------------------------------------------------
    // Core
    // -------------------------------------------------------------------------
    public:

        /**
         * Render this map on the given surface.
         * Only part under Camera view is to draw.
         *
         * \warning
         * Do nothing if dest is null.
         *
         * \param dest Surface where to draw.
         * \param cctv Camera view.
         */
        void render(SDL_Surface* dest, const Camera& cctv);


    // -------------------------------------------------------------------------
    // Getters - Setters
    // -------------------------------------------------------------------------
    public:

        /**
         * Returns the MapArea that is under given position.
         * Position is the absolute pixel position in the screen.
         * (0,0) is the upper-left corner of the screen.
         *
         * \param posX  X position in pixel.
         * \param posY  Y position in pixel.
         * \return      The MapArea under (x,y) position or NULL if none.
         */
        MapArea* getAreaAt(const int posX, const int posY);

        /**
         * Returns the Tile that is under given position.
         * Position is the absolute pixel position in the screen.
         * (0,0) is the upper-left corner of the screen.
         *
         * \param posX  X position in pixel.
         * \param posY  Y position in pixel.
         * \return      The Tile under (x,y) position or NULL if no tile
         */
        Tile* getTileAt(const int posX, const int posY);
};

