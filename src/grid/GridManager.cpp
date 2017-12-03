#include "grid/GridManager.h"

#include "utils/log.h"
#include "utils/gameConfig.h"

void GridManager::startup() {
    LOG_TRACE("Startup GridManager");
    this->m_XgridUnitSizeInPixels   = GRID_DEFAULT_X_UNIT_SIZE;
    this->m_YgridUnitySizeInPixels  = GRID_DEFAULT_Y_UNIT_SIZE;
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

int GridManager::getUnitX() const {
    return this->m_XgridUnitSizeInPixels;
}

int GridManager::getUnitY() const {
    return this->m_YgridUnitySizeInPixels;
}
