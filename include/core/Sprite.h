#pragma once

#include "utils/platform.h"
#include "utils/gameConfig.h"

#include <string>

class Texture;
class SDL_Surface;


/**
 * Sprite component.
 *
 * \date    Dev 2017
 * \author  Constantin Masson
 */
class Sprite {
    private:
        Texture* m_texture  = nullptr;
        int m_frameWidth    = GRID_DEFAULT_X_UNIT_SIZE;
        int m_frameHeight   = GRID_DEFAULT_Y_UNIT_SIZE;
        int m_posX          = 0;
        int m_posY          = 0;

    public:
        Sprite() = default;
        ~Sprite() = default;

    public:

        /**
         * Draw a sprite on a surface at a specific position.
         * Coordinates are the Sprite upper-left-corner.
         *
         * \param dest Surface where to render.
         * \param destX Sprite X coordinate on the surface.
         * \param destY Sprite Y coordinate on the surface.
         */
        void render(SDL_Surface* surface, const int destX, const int destY);


    // -------------------------------------------------------------------------
    // Getters - Setters
    // -------------------------------------------------------------------------
    public:
        int getFrameWidth() const;
        int getFrameHeight() const;
        int getFramePositionX() const;
        int getFramePositionY() const;

        void setFrameDimension(const int frameWidth, const int frameHeight);
        void setFramePosition(const int x, const int y);
        void setTexture(Texture* texture);
};
