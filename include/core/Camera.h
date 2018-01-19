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
        float m_x = 0;

        /** Camera position (in pixel). */
        float m_y = 0;

        /** X position of the camera target (In pixels). (Target mode). */
        const float* m_targetX = nullptr;

        /** Y position of the camera target (In pixels). (Target mode). */
        const float* m_targetY = nullptr;

        /** Zoom factor. */
        float m_zoomFactor = 1;

    private:
        int m_targetMode = CAMERA_MODE_NORMAL;


    //--------------------------------------------------------------------------
    // Initialization
    //--------------------------------------------------------------------------
    public:
        Camera() = default;
        ~Camera() = default;


    //--------------------------------------------------------------------------
    // Getters - Setters
    //--------------------------------------------------------------------------
    public:

        /**
         * Get X camera position.
         * Depending on camera mode, returns camera or target coordinates.
         *
         * \return X coordinate.
         */
        float getX() const;

        /**
         * Get Y camera position.
         * Depending on camera mode, returns camera or target coordinates.
         *
         * \return Y coordinate.
         */
        float getY() const;

        void setPosition(const float posX, const float posY);
        void setTarget(const float* posX, const float* posY);

        /**
         * Changes zoom factor.
         * Factor must be > 0 (Otherwise, do nothing).
         *
         * \param factor Zoom factor to apply.
         */
        void setZoomFactor(const float factor);
        float getZoomFactor() const;
};

