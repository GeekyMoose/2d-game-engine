#include "gamemap/MapArea.h"
#include "utils/log.h"

#include <stdio.h>


bool MapArea::loadFromFile(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if(file == NULL) {
        LOG_ERROR("Unable to open file: %s", file);
        return false;
    }

    for(int y = 0; y < AREA_NB_TILES_COL; ++y) {
        for(int x = 0; x < AREA_NB_TILES_ROW; ++x) {
            int tileType;
            fscanf(file, "%d ", tileType);
            this->m_tiles[x][y] = new Tile(x, y, tileType);
        }
        fscanf(file, "\n");
    }

    fclose(file);
    return true;
}

void MapArea::render(SDL_Surface* dest, const int destX, const int destY) {
    // TODO
}


//------------------------------------------------------------------------------
// Getters - Setters
//------------------------------------------------------------------------------
Tile* MapArea::getTile(const int posX, const int posY) {
    const int x = posX / TILE_SIZE_IN_PIXEL;
    const int y = posY / TILE_SIZE_IN_PIXEL;
    if(x >= 0 && x < AREA_NB_TILES_ROW && y >= 0 && y < AREA_NB_TILES_COL) {
        return this->m_tiles[x][y];
    }
    return nullptr;
}
