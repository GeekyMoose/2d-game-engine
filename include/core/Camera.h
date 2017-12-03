#pragma once

#include "utils/platform.h"


enum : int {
    CAMERA_MODE_NORMAL,         // Use camera's position as target.
    CAMERA_MODE_TARGET          // Use target's position as target.
};


/**
 * Camera component.
 * This is a 2D camera, it's position is also where camera is looking at.
 *
 * \note
 * Camera may be in one of the following modes
 * - Normal mode: camera targets its actual position (x,y)
 * - Target mode: camera use the set target position as its position.
 *
 * \author  Constantin Masson
 * \date    Oct 2017
 */
class Camera {
    //--------------------------------------------------------------------------
    // Attributes
    //--------------------------------------------------------------------------
    private:
        /** Camera position (in pixel). */
        float m_x;

        /** Camera position (in pixel). */
        float m_y;

        /** X position of the camera target (In pixels). (Target mode). */
        const float* m_targetX;

        /** Y position of the camera target (In pixels). (Target mode). */
        const float* m_targetY;

        /** The width size of the camera vision. */
        float m_width;

        /** The height size of the camera vision. */
        float m_height;

    private:
        int m_targetMode;


    //--------------------------------------------------------------------------
    // Initialization
    //--------------------------------------------------------------------------
    public:
        Camera();
        ~Camera() = default;


    //--------------------------------------------------------------------------
    // Getters - Setters
    //--------------------------------------------------------------------------
    public:

        /**
         * Returns X camera position (In pixels).
         * Depending on camera mode, returns camera or target coordinates.
         *
         * \return X coordinate.
         */
        float getX() const;

        /**
         * Returns Y camera position (In pixels).
         * Depending on camera mode, returns camera or target coordinates.
         *
         * \return Y coordinate.
         */
        float getY() const;

        void setPosition(const float posX, const float posY);
        void setTarget(const float* posX, const float* posY);

        float getWidth() const;
        float getHeight() const;
};

