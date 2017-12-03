#include "grid/TileMap.h"

#include "utils/log.h"
#include "core/SpriteManager.h"
#include "core/Camera.h"
#include "grid/GridManager.h"

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

void TileMap::render(SDL_Surface* dest, Camera* cctv) {
    // TODO: Draw only part under camera vision
    const int xshift = cctv->getX() - (cctv->getWidth() / 2);
    const int yshift = cctv->getY() - (cctv->getHeight() / 2);

    for(int col = 0; col < this->m_tilesPerColumn; ++col) {
        for(int row = 0; row < this->m_tilesPerRow; ++row) {
            const int x = row * GridManager::getInstance().getUnitX() - xshift;
            const int y = col * GridManager::getInstance().getUnitY() - yshift;
            this->m_tiles[col][row].render(dest, x, y);
        }
    }
}

