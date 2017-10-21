#include "Map.h"

Map::Map() {
    tilesSprites = NULL;
}

bool Map::loadMap(const char * file) {
    listTiles.clear();
    FILE* filehandler = fopen(file, "r");

    if(filehandler == NULL) {
        LOG_ERROR("Unable to open file");
        return false;
    }

    //Recover data from file
    for(int y = 0; y<MAP_HEIGHT; y++) {
        for(int x = 0; x<MAP_WIDTH; x++) {
            Tile tmpTile;
            fscanf(filehandler, "%d:%d ", &tmpTile.tileID, &tmpTile.typeID);
            listTiles.push_back(tmpTile);
        }
        fscanf(filehandler, "\n");
    }
    fclose(filehandler);
    return true;
}

void Map::renderMap(SDL_Surface* dest, int mapX, int mapY) {
    if(dest==NULL || tilesSprites==NULL) {
        return;
    }

    //Get nb of tiles in a row and in a column
    int nbTilesW = tilesSprites->w/TILE_SIZE;
    int nbTilesH = tilesSprites->h/TILE_SIZE; //Actually not used

    //Draw each tile from the map
    int id = 0;
    for(int y = 0; y<MAP_HEIGHT; y++) {
        for(int x = 0; x<MAP_WIDTH; x++) {
            if(listTiles[id].typeID==TILE_TYPE_NONE) {
                id++;
                continue;
            }
            //Coordinate of the tile in the actual dest surface
            int tx = mapX+(x*TILE_SIZE);
            int ty = mapY+(y*TILE_SIZE);

            //Recover part of sprite to draw from sprite-sheet
            int srcX = (listTiles[id].tileID % nbTilesW) * TILE_SIZE;
            int srcY = (listTiles[id].tileID / nbTilesW) * TILE_SIZE;

            //Draw and go to next
            Surface::doDraw(tilesSprites, srcX, srcY, TILE_SIZE, TILE_SIZE, dest, tx, ty);
            id++;
        }
    }
}

Tile* Map::getTile(int posX, int posY) {
    int id = (posX/TILE_SIZE) + (MAP_WIDTH * (posY/TILE_SIZE));
    if(id < 0 || id >= listTiles.size()) {
        return nullptr;
    }
    return &listTiles[id];
}
