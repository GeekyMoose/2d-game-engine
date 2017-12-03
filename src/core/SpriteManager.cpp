#include "core/SpriteManager.h"

#include <utility>
#include <iterator>


void SpriteManager::startup() {
    this->m_sprites.clear();
}

void SpriteManager::shutdown() {
    this->m_sprites.clear();
}


Sprite* SpriteManager::createSprite(const char* name) {
    auto elt = this->m_sprites.emplace(std::make_pair(name, Sprite{}));
    Sprite* sprite = &(elt.first->second);
    return sprite;
}

Sprite* SpriteManager::getSpriteByName(const char* name) {
    try {
        Sprite& sprite = this->m_sprites.at(name);
        return &sprite;
    }
    catch (std::out_of_range& exception) {
        return nullptr;
    }
}
