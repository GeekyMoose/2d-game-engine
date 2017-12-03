#include "grid/TileMap.h"

#include "utils/log.h"
#include "core/SpriteManager.h"

class Sprite;


bool TileMap::loadFromFile(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if(file == NULL) {
        LOG_ERROR("Unable to load TileMap from file: %s", filepath);
        return false;
    }

    // TODO: sprite and texture loading for the map are hard coded here for now
    Sprite *sprite = SpriteManager::getInstance().getSpriteByName(SPRITE_TILE_NAME);
    int tileType = 0;

    for(int col = 0; col < this->m_tilesPerColumn; ++col){
        for(int row = 0; row < this->m_tilesPerRow; ++row){
            fscanf(file, "%d ", &tileType);
            this->m_tiles[col][row].setType(tileType);
            this->m_tiles[col][row].setSprite(sprite);
        }
        fscanf(file, "\n");
    }

    fclose(file);
    return true;
}
