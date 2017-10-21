#include "Animation.h"

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

int Animation::getCurrentFrame() {
    return currentFrame;
}

void Animation::setNbFrames(int value) {
    if(value<0) { return; }
    nbFrames = value;
}

void Animation::setCurrentFrame(int frame) {
    if(frame<0||frame>=nbFrames) { return; }
    currentFrame = frame;
}

void Animation::setAnimSpeed(int speed) {
    if(speed<=0) { return; }
    animSpeed = speed;
}
