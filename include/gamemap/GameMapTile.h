#pragma once

enum GameMapTileType {
    Normal,
    Block
};


/**
 * Smallest component of a GameMap: the tile.
 * A tile is inside a GameMapArea at a specific position (x,y).
 * It's position is relative to its parent MapArea.
 */
class GameMapTile {
    private:
        /** X Coordinate of the Tile in MapArea's coordinates. */
        const int m_coordinateX;

        /** Y Coordinate of the Tile in MapArea's coordinates. */
        const int m_coordinateY;

        /** Type of tile. From enum. */
        const GameMapTileType m_tileType;

    public:
        GameMapTile(const int x, const int y, const GameMapTileType type);
};
