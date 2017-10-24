#pragma once

#include "core/Map.h"

#include "sdl/Surface.h"

#include <vector>


/**
 * Describe an Area.
 * Area is composed by a set of Maps.
 */
class Area {

    //--------------------------------------------------------------------------
    // Constants - Attributes
    //--------------------------------------------------------------------------
    public:
        static Area areaControl; //Just a public access to this area class

    public:
        /** List of maps in this area */
        std::vector<Map> listMap;

    private:
        /** Assume always square, so size 3 means 3x3 maps */
        int areaSize;

        /** Sprite-sheet with all tiles images (sprites) */
        SDL_Surface* tilesSprites;


    //--------------------------------------------------------------------------
    // Initialization
    //--------------------------------------------------------------------------
    public:
        Area();


    //--------------------------------------------------------------------------
    // Body functions
    //--------------------------------------------------------------------------
    public:

        /**
         * \brief           Load an Area from file save.
         * \warning         Unsafe result if invalid file format or data.
         *
         * \param file      File to load (Path + name + extension).
         * \return          True if successfully loaded, otherwise, return false.
         */
        bool loadArea(const char* file);

        /**
         * \brief           Render the Area on the destination.
         * \warning         Camera coordinate different coordinates. Therefore they
         *                  are often negative here. In camera coordinates:
         *                  X axis direction is to the left.
         *                  Y axis direction is up.
         *                  However, display use 0.0 for the upper left corner.
         * 
         * \param dest      Surface where to draw area.
         * \param cameraX   coordinate X of the camera on the area (In pixels).
         * \param cameraY   coordinate Y of the camera on the area (In pixels).
         */
        void renderArea(SDL_Surface* dest, int cameraX, int cameraY);

        /**
         * \brief Cleanup this Area.
         * Free allocated memory and reset values.
         */
        void cleanupArea();


    //--------------------------------------------------------------------------
    // Getters - Setters
    //--------------------------------------------------------------------------
    public:
        /**
         * \brief           Returns the map that is under given position
         * \details         Position is the absolute pixel position in the screen.
         *
         * \param posX      X position
         * \param posY      Y position
         * \return          The Map under (x,y) position or NULL if no map
         */
        Map* getMap(int posX, int posY);

        /**
         * \brief           Returns the tile that is under given position
         * \details         Position is the absolute pixel position in the screen.
         *
         * \param posX      X position
         * \param posY      Y position
         * \return          The Tile under (x,y) position or NULL if no tile
         */
        Tile* getTile(int posX, int posY);
};
