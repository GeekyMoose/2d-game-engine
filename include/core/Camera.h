#pragma once

#include "helper/Platform.h"
#include "helper/gameConfig.h"


enum {
    TARGET_MODE_NORMAL = 0, //Position to the top left of the target
    TARGET_MODE_CENTER      //Center camera to the target
};


class Camera {
    //--------------------------------------------------------------------------
    // Attributes
    //--------------------------------------------------------------------------
    public:
        static Camera cameraControl; //To access camera from anywhere

    private:
        /** Camera position (in pixel). Note: is actually the upperLeftCorner. */
        float   x;

        /** Camera position (in pixel). Upper Left Corner Y. */
        float   y;

        /** Targeted element or null if no target). */
        float*  targetX;
        float*  targetY;

    public:
        int targetMode;


    //--------------------------------------------------------------------------
    // Initialization
    //--------------------------------------------------------------------------
    public:
        Camera();


    //--------------------------------------------------------------------------
    // Body functions
    //--------------------------------------------------------------------------
    public:

        /**
         * \brief   Move the camera
         * 
         * \param   moveX X coordinate translation
         * \param   moveY Y coordinate translation
         */
        void moveCamera(int moveX, int moveY);

        /**
         * \brief   Return X camera position
         * \details The returned value depend if a target is set and use the camera mode.
         *
         * \return  Current X coordinate
         */
        int getX();

        /**
        * \brief    Return Y camera position
        * \details  The returned value depend if a target is set and use the camera mode.
        *
        * \return   Current Y coordinate
        */
        int getY();

        void setPosition(float posX, float posY);
        void setTarget(float* posX, float* posY);
};

