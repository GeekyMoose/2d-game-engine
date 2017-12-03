#pragma once

#include "utils/platform.h"

#include <string>

class Texture;


/**
 * Sprite component.
 *
 * \date    Dev 2017
 * \author  Constantin Masson
 */
class Sprite {
    private:
        Texture* m_texture;
        int m_frameWidth;
        int m_frameHeight;
        int m_posX;
        int m_posY;

    public:
        Sprite() = default;
        ~Sprite() = default;

    public:
        void setFrameDimension(const int frameWidth, const int frameHeight);
        void setFramePosition(const int x, const int y);
        void setTexture(Texture* texture);
};
