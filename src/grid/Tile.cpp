#include "grid/Tile.h"

#include "core/SpriteManager.h"
#include "core/Sprite.h"


void Tile::render(SDL_Surface* dest, const int destX, const int destY) {
    // TODO
}

void Tile::setType(const int type) {
    this->m_tileType = type;
}

int Tile::getType() const {
    return this->m_tileType;
}
