#include "core/Sprite.h"


void Sprite::setFrameDimension(const int frameWidth, const int frameHeight) {
    this->m_frameWidth =  frameWidth;
    this->m_frameHeight = frameHeight;
}

void Sprite::setFramePosition(const int x, const int y) {
    this->m_posX = x;
    this->m_posY = y;
}

void Sprite::setTexture(Texture* texture) {
    this->m_texture = texture;
}
