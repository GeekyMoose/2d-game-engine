#include "grid/GameMap.h"
#include "utils/log.h"

bool GameMap::loadFromFile(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if(file == NULL) {
        LOG_ERROR("Unable to load GameMap from file: %s", filepath);
        return false;
    }

    //Recover each area row (One line each in file)
    for(int y = 0; y < MAP_SIZE_COL; ++y){
        for(int x = 0; x < MAP_SIZE_ROW; ++x){
            char buffer[256];
            fscanf(file, "%s", buffer);
            if(this->m_areas[y][x].loadFromFile(buffer) == false) {
                LOG_ERROR("Unable to load GameMap area %s", buffer);
                fclose(file);
                return false;
            }
            fscanf(file, "\n");
        }
        fscanf(file, "\n");
    }
    fclose(file);
    return true;
}

void GameMap::render(SDL_Surface* dest, const Camera& cctv) {
    if(dest == NULL){
        return;
    }

    const int areaRowSize = AREA_NB_TILES_ROW * TILE_SIZE_IN_PIXEL;
    const int areaColSize = AREA_NB_TILES_COL * TILE_SIZE_IN_PIXEL;

    // TODO To update with algo to draw only area in vision
    for(int col = 0; col < MAP_SIZE_COL; ++col) {
        for(int row = 0; row < MAP_SIZE_ROW; ++row) {
            int x = row * areaRowSize - cctv.getX() - (cctv.getWidth() / 2);
            int y = col * areaColSize - cctv.getY() - (cctv.getHeight() / 2);
            this->m_areas[col][row].render(dest, x, y);
        }
    }
}

MapArea* GameMap::getAreaAt(const int posX, const int posY) {
    int x = posX / (AREA_NB_TILES_ROW * TILE_SIZE_IN_PIXEL);
    int y = posY / (AREA_NB_TILES_COL * TILE_SIZE_IN_PIXEL);

    if(x >= 0 && x < MAP_SIZE_ROW && y >= 0 && y < MAP_SIZE_COL) {
        return &this->m_areas[y][x];
    }
    return nullptr;
}

Tile* GameMap::getTileAt(const int posX, const int posY) {
    MapArea* area = this->getAreaAt(posX, posY);
    if(area == nullptr) {
        return nullptr;
    }

    const int areaRowSize = AREA_NB_TILES_ROW * TILE_SIZE_IN_PIXEL;
    const int areaColSize = AREA_NB_TILES_COL * TILE_SIZE_IN_PIXEL;

    const int x = posX % areaRowSize;
    const int y = posY % areaColSize;
    return area->getTileAt(x, y);
}

