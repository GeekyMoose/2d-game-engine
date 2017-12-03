#include "core/Sprite.h"

#include "utils/SDLHelper.h"
#include "core/Texture.h"

void Sprite::render(SDL_Surface* dest, const int destX, const int destY) {
    if(this->m_texture != nullptr) {
        SDL_Surface* src = this->m_texture->getSurface();
        SDLHelper::drawOnSurface(
                src,
                this->m_posX,
                this->m_posY,
                this->m_frameWidth,
                this->m_frameHeight,
                dest,
                destX,
                destY);
    }
}


// -----------------------------------------------------------------------------
// Getters - Setters
// -----------------------------------------------------------------------------
int Sprite::getFrameWidth() const {
    return this->m_frameWidth;
}

int Sprite::getFrameHeight() const {
    return this->m_frameHeight;
}

int Sprite::getFramePositionX() const {
    return this->m_posX;
}

int Sprite::getFramePositionY() const {
    return this->m_posY;
}

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
