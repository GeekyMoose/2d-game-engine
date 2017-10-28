#include "core/Animation.h"

#if PLATFORM_WINDOWS
#   include <SDL.h>
#elif PLATFORM_LINUX
#   include <SDL2/SDL.h>
#endif


Animation::Animation() {
    currentFrame= 0;
    nextFrame = 1;
    animSpeed = 100;
    nbFrames = 0;
    oldTime = 0;
    oscillate = false;
}

void Animation::doAnimate() {
    int currentTime = SDL_GetTicks();
    if(currentTime - oldTime < animSpeed) {
        return;
    }
    oldTime = currentTime;
    currentFrame += nextFrame;

    if(oscillate) {
        if(nextFrame>0) {
            if(currentFrame>=nbFrames) {
                nextFrame = -nextFrame;
            }
        }
        else{
            if(currentFrame<=0) {
                nextFrame = -nextFrame;
            }
        }
    }
    else{
        if(currentFrame >= nbFrames) {
            currentFrame = 0;
        }
    }
}

int Animation::getCurrentFrame() const {
    return currentFrame;
}

void Animation::setNbFrames(const int value) {
    if(value >= 0) {
        this->nbFrames = value;
    }
}

void Animation::setCurrentFrame(const int frame) {
    if(frame >= 0 && frame < this->nbFrames) {
        currentFrame = frame;
    }
}

void Animation::setAnimSpeed(const int speed) {
    if(speed > 0) {
        this->animSpeed = speed;
    }
}
