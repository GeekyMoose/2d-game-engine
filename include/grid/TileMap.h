#pragma once

#include "utils/platform.h"


/**
 * Defines a tilemap.
 *
 * \date    Dec 2017
 * \author  Constantin Masson
 */
class TileMap {
    private:
        const int m_width;
        const int m_heigh;

        Tile m_tiles[m_width][m_heigh];

    public:
        TileMap(const int w, const int heigh);
        ~TileMap() = default;

    public:
        /**
         *
         * \warning
         * Undefined behavior in case of wrong file format.
         * May be security issue.
         *
         * \param file  File to use (Whole path + name + extension).
         * \return      True if successfully loaded, otherwise, return false.
         */
        bool loadFromFile(const char* file);
};
