#include "Area.h"

Area Area::areaControl;

Area::Area(){
	areaSize = 0;
}

Area::~Area(){
}

bool Area::loadArea(const char* file){
	listMap.clear();

	//Open file and check error
	FILE* filehandler = fopen(file, "r");
	if(filehandler==NULL){ return false; }

	//Recover the tileset (spritesheet)
	char tilesetFile[255];
	fscanf(filehandler, "%s\n", tilesetFile);
	tilesSprites = Surface::doLoad(tilesetFile);
	if(tilesSprites==NULL){
		fclose(filehandler);
		return false; 
	}

	//Recover area size
	fscanf(filehandler, "%d\n", &areaSize);

	//Recover each map
	for(int x = 0; x<areaSize; x++){
		for(int y = 0; y<areaSize; y++){
			char mapFile[255];
			fscanf(filehandler, "%s ", mapFile);
			Map tmpMap;
			if(tmpMap.loadMap(mapFile)==false){
				fclose(filehandler);
				return false;
			}
			tmpMap.tilesSprites = tilesSprites;
			listMap.push_back(tmpMap);
		}
		fscanf(filehandler, "\n");
	}
	fclose(filehandler);
	return true;
}

void Area::renderArea(SDL_Surface * dest, int cameraX, int cameraY){
	//Actual map size in window
	int mapW = MAP_WIDTH * TILE_SIZE;
	int mapH = MAP_HEIGHT * TILE_SIZE;

	//Get the ID of the first map to display (Don't draw map outside the camera)
	int firstID = -cameraX/mapW;
	firstID = firstID+((-cameraY/mapH) * areaSize);

	//TODO
}

void Area::cleanupArea(){
	SDL_FreeSurface(tilesSprites);
	listMap.clear();
}