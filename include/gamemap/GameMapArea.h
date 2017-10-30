#pragma once

#include "gamemap/GameMapTile.h"
#include "helper/gameConfig.h"


/**
 * SubComponent of a GameMap.
 *
 * GameMapArea is made of Tiles.
 */
class GameMapArea {
    private:
        /** X Position of the Area inside it's GameMap parent. */
        const int m_coordinateX;

        /** Y Position of the Area inside it's GameMap parent. */
        const int m_coordinateY;

        /** Matrix of tiles. */
        GameMapTile* m_tiles[GameMapData::AREA_NB_TILES_ROW][GameMapData::AREA_NB_TILES_COL];


    private:
        GameMapArea(const int x, const int y);
        ~GameMapArea() = default;

    public:
        static void loadMapFromFile(const char* file);
};