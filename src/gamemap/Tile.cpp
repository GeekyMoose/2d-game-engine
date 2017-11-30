#include "gamemap/Tile.h"

Tile::Tile(const int x, const int y, const int type)
    : m_coordinateX(x),
      m_coordinateY(y),
      m_tileType(type) {
}

void Tile::render(SDL_Surface* dest, const int destX, const int destY) {
    // TODO
}
