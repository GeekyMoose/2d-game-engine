#include "gamemap/Tile.h"

Tile::Tile(const int x, const int y, const TileType type)
    : m_coordinateX(x),
      m_coordinateY(y),
      m_tileType(type) {
}
