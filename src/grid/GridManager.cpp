#include "grid/GridManager.h"

#include "utils/log.h"

void GridManager::startup() {
    LOG_TRACE("Startup GridManager");
}

void GridManager::shutdown() {
    LOG_TRACE("Shutdown GridManager");
}

Point2D GridManager::convertPixelToGrid(const int x, const int y) const {
    const int gridX = x / this->m_XgridUnitSizeInPixels;
    const int gridY = y / this->m_YgridUnitySizeInPixels;
    return Point2D(gridX, gridY);
}

Point2D GridManager::convertGridToPixel(const int x, const int y) const {
    const int pX = x * this->m_XgridUnitSizeInPixels;
    const int pY = y * this->m_YgridUnitySizeInPixels;
    return Point2D(pX, pY);
}
