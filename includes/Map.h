#pragma once

#include "Tile.h"
#include "Surface.h"
#include "constants.h"
#include "helper/Logger.h"

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#pragma warning(disable:4996) //Allow unsafe fopen / fscanf
#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE //Allow unsafe fopen / fscanf
#endif


/**
 * Describe a Map element
 * Map is composed by a set of Tiles
 */
class Map {
    //--------------------------------------------------------------------------
    // Constants - Attributes
    //--------------------------------------------------------------------------
    public:
        SDL_Surface* tilesSprites; //Pointer to the tiles sprite-sheet for this map
    private:
        std::vector<Tile> listTiles; //All loaded tiles for this map


    //--------------------------------------------------------------------------
    // Constructors
    //--------------------------------------------------------------------------
    public:
        Map();


    //--------------------------------------------------------------------------
    // Corps functions
    //--------------------------------------------------------------------------
    public:

        /**
         * \brief           Load a Map using file save.
         * \warning         Unsafe result if invalid file format or data.
         * 
         * \param file      File to load (Path + name + extension).
         * \return          True if loaded successfully, otherwise, return false.
         */
        bool loadMap(const char* file);

        /**
         * \brief           Render map on a surface.
         * \warning         Map must have been loaded successfully otherwise, do nothing.
         * 
         * \param dest      SDL_Surface destination where to render map.
         * \param mapX      X coordinate where to draw map on the dest.
         * \param mapY      Y coordinate where to draw map on the dest.
         */
        void renderMap(SDL_Surface* dest, int mapX, int mapY);


    //--------------------------------------------------------------------------
    // Getters - Setters
    //--------------------------------------------------------------------------
    public:

        /**
         * \brief           Return a tile at specific position on the map
         * \details         Position is in pixel. Get the actual Tile at this pixel
         *                  position or null if no tile here.
         *
         * \param posX      X position in pixel.
         * \param posY      Y position in pixel.
         * \return          The tile at position x,y or nullptr if no tile
         */
        Tile* getTile(int posX, int posY);
};

