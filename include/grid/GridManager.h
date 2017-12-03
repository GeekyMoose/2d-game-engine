#pragma once

#include "utils/Singleton.h"
#include "Point2D.h"


/**
 * GridManager.
 * This engine works with a grid system.
 * The smallest world unit is a grid unit.
 * This works closely with TileMap where a tile has the size of a GridUnit.
 *
 * \date    Dec 2017
 * \author  Constantin Masson
 */
class GridManager : private Singleton<GridManager> {
    private:
        friend Singleton<GridManager>;
    public:
        using Singleton<GridManager>::getInstance;

    private:
        int m_XgridUnitSizeInPixels;
        int m_YgridUnitySizeInPixels;

    private:
        GridManager() = default;
        ~GridManager() = default;

    public:
        void startup() override;
        void shutdown() override;

    public:
        Point2D convertPixelToGrid(const int x, const int y) const;
        Point2D convertGridToPixel(const int x, const int y) const;
        int getUnitX() const;
        int getUnitY() const;
};
