#include "core/Camera.h"
#include "utils/gameConfig.h"

Camera::Camera() {
    this->m_x           = 0;
    this->m_y           = 0;
    this->m_targetX     = nullptr;
    this->m_targetY     = nullptr;
    this->m_targetMode  = CAMERA_MODE_NORMAL;
    this->m_width       = CAMERA_DEFAULT_WIDTH;
    this->m_height      = CAMERA_DEFAULT_HEIGHT;
}

float Camera::getX() const {
    if(this->m_targetMode == CAMERA_MODE_TARGET) {
        return *m_targetX;
    }
    return this->m_x;
}

float Camera::getY() const {
    if(this->m_targetMode == CAMERA_MODE_TARGET) {
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

float Camera::getWidth() {
    return this->m_width;
}

float Camera::getHeight() {
    return this->m_height;
}
