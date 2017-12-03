#include "grid/MapArea.h"
#include "utils/log.h"

#include <stdio.h>


bool MapArea::loadFromFile(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if(file == NULL) {
        LOG_ERROR("Unable load area from file: %s", filepath);
        return false;
    }

    // Recover tiles (Number, then space and \n each row)
    for(int y = 0; y < AREA_NB_TILES_COL; ++y) {
        for(int x = 0; x < AREA_NB_TILES_ROW; ++x) {
            int tileType = 0;
            fscanf(file, "%d ", &tileType);
            this->m_tiles[y][x] = new Tile(x, y, tileType);
        }
        fscanf(file, "\n");
    }

    fclose(file);
    return true;
}

void MapArea::render(SDL_Surface* dest, const int destX, const int destY) {
    for(int col = 0; col < AREA_NB_TILES_COL; ++col) {
        for(int row = 0; row < AREA_NB_TILES_ROW; ++row) {
            int x = destX + TILE_SIZE_IN_PIXEL * row;
            int y = destY + TILE_SIZE_IN_PIXEL * col;
            this->m_tiles[col][row]->render(dest, x, y);
        }
    }
}


//------------------------------------------------------------------------------
// Getters - Setters
//------------------------------------------------------------------------------
Tile* MapArea::getTileAt(const int posX, const int posY) {
    const int x = posX / TILE_SIZE_IN_PIXEL;
    const int y = posY / TILE_SIZE_IN_PIXEL;
    if(x >= 0 && x < AREA_NB_TILES_ROW && y >= 0 && y < AREA_NB_TILES_COL) {
        return this->m_tiles[y][x];
    }
    return nullptr;
}
