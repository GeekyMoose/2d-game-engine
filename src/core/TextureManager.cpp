#include "core/TextureManager.h"

#include <utility>
#include <iterator>


void TextureManager::startup() {
    this->m_textures.clear();
}

void TextureManager::shutdown() {
    this->m_textures.clear();
}

Texture* TextureManager::createTexture(const char* name, const char* path) {
    auto elt = this->m_textures.emplace(std::make_pair(name, name));
    Texture* texture = &(elt.first->second);
    texture->loadFromFile(path);
    return texture;
}

Texture* TextureManager::getTextureByName(const char* name) {
    try {
        Texture& texture = this->m_textures.at(name);
        return &texture;
    }
    catch (std::out_of_range& exception) {
        return nullptr;
    }
}
