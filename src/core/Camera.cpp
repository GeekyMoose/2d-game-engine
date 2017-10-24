#include "core/Camera.h"

Camera Camera::cameraControl;


Camera::Camera() {
    x           = 0;
    y           = 0;
    targetX     = nullptr;
    targetY     = nullptr;
    targetMode  = TARGET_MODE_NORMAL;
}

void Camera::moveCamera(int moveX, int moveY) {
    x += moveX;
    y += moveY;
}

int Camera::getX() {
    //If no target, return current position
    if(targetX == nullptr) {
        return x;
    }
    //Here, means target set, return position according to camera mode
    if(targetMode == TARGET_MODE_CENTER) {
        return *targetX - (WINDOW_DEFAULT_WIDTH / 2);
    }
    return *targetX;
}

int Camera::getY() {
    //If no target, return current position
    if(targetY == nullptr) {
        return y;
    }
    //Here, means target set, return position according to camera mode
    if(targetMode == TARGET_MODE_CENTER) {
        return *targetY - (WINDOW_DEFAULT_HEIGHT / 2);
    }
    return *targetY;
}

void Camera::setPosition(float posX, float posY) {
    x = posX;
    y = posY;
}

void Camera::setTarget(float *posX, float* posY) {
    targetX = posX;
    targetY = posY;
}
