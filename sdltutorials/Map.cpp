#include "Map.h"

Map::Map(){
	tilesSprites = NULL;
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
	if(dest==NULL ||tilesSprites==NULL) { return; }
	
	//Get nb of tiles in a row and in a column
	int nbTilesW = tilesSprites->w/TILE_SIZE;
	int nbTilesH = tilesSprites->h/TILE_SIZE;
	int id = 0;

	//Draw each tile from the map
	for(int y = 0; y<MAP_HEIGHT; y++){
		for(int x = 0; x<MAP_WIDTH; x++){
			if(listTiles[id].typeID==TILE_TYPE_NONE){
				id++;
				continue;
			}
			//Coordinate of the tile in the actual dest surface
			int tx = mapX+(x*TILE_SIZE);
			int ty = mapY+(y*TILE_SIZE);

			//Recover part of sprite to draw from spritesheet
			int srcX = (listTiles[id].tileID % nbTilesW) * TILE_SIZE;
			int srcY = (listTiles[id].tileID/nbTilesH) * TILE_SIZE;

			//Draw and go to next
			Surface::doDraw(tilesSprites, srcX, srcY, TILE_SIZE, TILE_SIZE, dest, tx, ty);
			id++;
		}
	}
}
