#pragma once
#include <SDL2/SDL.h>


/**
 * Define an animation.
 */
class Animation {
    private:
        int currentFrame;

        /** Total nb of frame in animation */
        int nbFrames;

        /** In milliseconds, time between to frames */
        int animSpeed;

        /** Time when last change was done */
        int oldTime;

    public:
        /** Define the distance to next frame (usually 1 or -1) */
        int nextFrame;

        /** If not oscillate, go back to 0 when reach last frame */
        int oscillate;


    public:
        Animation();

        /**
         * Process animation, currentFrame change condition reached
         *
         * Check the difference between currentTime and oldTime (Gives delta time). 
         * If animSpeed is higher than this value, animation change.
         */
        void doAnimate();

    public:
        int getCurrentFrame();
        void setNbFrames(int nbFrames);
        void setCurrentFrame(int frame);
        void setAnimSpeed(int speed);
};

