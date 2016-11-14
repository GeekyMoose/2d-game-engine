#include "Map.h"

Map::Map(){
	surfaceTiles = NULL;
}

Map::~Map(){
}

bool Map::loadMap(const char * file){
	listTiles.clear();
	FILE* filehandler = fopen(file, "r");
	if(filehandler==NULL){ return false; }
	
	//Recover data from file
	for(int y = 0; y<MAP_HEIGHT; y++){
		for(int x = 0; x<MAP_WIDTH; x++){
			Tile tmpTile;
			fscanf(filehandler, "%d:%d ", &tmpTile.tileID, &tmpTile.typeID);
			listTiles.push_back(tmpTile);
		}
		fscanf(filehandler, "\n");
	}
	fclose(filehandler);
	return true;
}

void Map::renderMap(SDL_Surface* dest, int mapX, int mapY){
	if(dest==NULL) { return; }
	
	int surfaceTilesWidth = surfaceTiles->w/TILE_SIZE;
	int surfaceTilesHeight = surfaceTiles->h/TILE_SIZE;
	int id = 0;

	for(int y = 0; y<MAP_HEIGHT; y++){
		for(int x = 0; x<MAP_WIDTH; x++){
			if(listTiles[id].typeID==TILE_TYPE_NONE){
				id++;
				continue;
			}
			int tx = mapX+(x*TILE_SIZE);
			int ty = mapY+(y*TILE_SIZE);

			int tilesetX = (listTiles[id].tileID % surfaceTilesWidth) * TILE_SIZE;
			int tilesetY = (listTiles[id].tileID/surfaceTilesHeight) * TILE_SIZE;

			//TODO add Draw function
			id++;
		}
	}
}
