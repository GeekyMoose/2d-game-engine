#pragma once

#include "Tile.h"

#include "helper/gameConfig.h"
#include "helper/Logger.h"
#include "helper/gameConfig.h"

#include "sdl/Surface.h"

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>


/**
 * Map component.
 * Map is composed of tiles.
 */
class Map {
    //--------------------------------------------------------------------------
    // Constants - Attributes
    //--------------------------------------------------------------------------
    
    public: //TODO To change for private later
        /** Pointer to the sprite-sheet */
        SDL_Surface* m_tilesSprites;

    private:
        /** List of loaded tiles */
        std::vector<Tile> m_listTiles;


    //--------------------------------------------------------------------------
    // Constructors
    //--------------------------------------------------------------------------
    public:
        Map() = default;
        ~Map() = default;


    //--------------------------------------------------------------------------
    // Corps functions
    //--------------------------------------------------------------------------
    public:

        /**
         * Load a Map from a file.
         * File format must be valid.
         *
         * \param file  File to load (Path + name + extension).
         * \return      True if loaded successfully, otherwise, return false.
         */
        bool loadMapFromFile(const char* file);

        /**
         * Render map on a surface.
         * Map must have been loaded successfully otherwise, do nothing.
         *
         * \param dest  Surface destination where to render map.
         * \param mapX  X coordinate where to draw map on the dest.
         * \param mapY  Y coordinate where to draw map on the dest.
         */
        void renderMap(SDL_Surface* dest, const int mapX, const int mapY);


    //--------------------------------------------------------------------------
    // Getters - Setters
    //--------------------------------------------------------------------------
    public:

        /**
         * Returns the map's tile under pixel (x,y).
         *
         * \note
         * Position is in pixel. Get the actual Tile at this pixel
         * position or null if no tile here.
         *
         * \param posX  X position in pixel.
         * \param posY  Y position in pixel.
         * \return      The tile at position (x,y) or nullptr if no tile.
         */
        Tile* getTile(const int posX, const int posY);
};

