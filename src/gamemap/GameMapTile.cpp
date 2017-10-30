#include "gamemap/GameMapTile.h"

GameMapTile::GameMapTile(const int x, const int y, const GameMapTileType type)
    : m_coordinateX(x), m_coordinateY(y), m_tileType(type) {
}