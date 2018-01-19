#include "core/Camera.h"
#include "utils/gameConfig.h"

#include <cassert>


float Camera::getX() const {
    if(this->m_targetMode == CAMERA_MODE_TARGET) {
        assert(this->m_targetX != nullptr);
        return *m_targetX;
    }
    return this->m_x;
}

float Camera::getY() const {
    if(this->m_targetMode == CAMERA_MODE_TARGET) {
        assert(this->m_targetY != nullptr);
        return *m_targetY;
    }
    return this->m_y;
}

void Camera::setPosition(const float x, const float y) {
    this->m_x = x;
    this->m_y = y;
}

void Camera::setTarget(const float* targetX, const float* targetY) {
    this->m_targetX = targetX;
    this->m_targetY = targetY;
}

float Camera::getZoomFactor() const {
    return this->m_zoomFactor;
}

void Camera::setZoomFactor(const float factor) {
    assert(factor > 0);
    if(factor > 0) {
        this->m_zoomFactor = factor;
    }
}
