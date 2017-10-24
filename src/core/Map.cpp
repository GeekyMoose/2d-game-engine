#include "core/Map.h"

#include <iostream>

bool Map::loadMapFromFile(const char* file) {
    this->m_listTiles.clear();
    FILE* filehandler = fopen(file, "r");

    if(filehandler == NULL) {
        LOG_ERROR("Unable to open file");
        return false;
    }

    for(int y = 0; y < MAP_NB_TILES_HEIGHT; y++) {
        for(int x = 0; x < MAP_NB_TILES_WIDTH; x++) {
            Tile tmpTile;
            fscanf(filehandler, "%d:%d ", &tmpTile.tileID, &tmpTile.typeID);
            m_listTiles.push_back(tmpTile);
        }
        fscanf(filehandler, "\n");
    }

    fclose(filehandler);
    return true;
}

void Map::renderMap(SDL_Surface* dest, const int mapX, const int mapY) {
    if(dest == NULL || m_tilesSprites == NULL) {
        return;
    }

    const int nbTilesByRow = m_tilesSprites->w / TILE_SIZE;

    int id = 0;
    for(int y = 0; y < MAP_NB_TILES_HEIGHT; ++y) {
        for(int x = 0; x < MAP_NB_TILES_WIDTH; ++x) {

            if(m_listTiles[id].typeID == TILE_TYPE_NONE) {
                id++;
                continue;
            }

            //Coordinate of the tile in the actual dest surface
            const int tx = mapX + (x * TILE_SIZE);
            const int ty = mapY + (y * TILE_SIZE);

            //Recover part of sprite to draw from sprite-sheet
            int srcX = (m_listTiles[id].tileID % nbTilesByRow) * TILE_SIZE;
            int srcY = (m_listTiles[id].tileID / nbTilesByRow) * TILE_SIZE;

            //Draw and go to next
            Surface::drawInSurface(m_tilesSprites, srcX, srcY, TILE_SIZE, TILE_SIZE, dest, tx, ty);
            id++;
        }
    }
}

Tile* Map::getTile(const int posX, const int posY) {
    int id = (posX / TILE_SIZE) + (MAP_NB_TILES_WIDTH * (posY / TILE_SIZE));
    if(id < 0 || id >= m_listTiles.size()) {
        return nullptr;
    }
    return &m_listTiles[id];
}
