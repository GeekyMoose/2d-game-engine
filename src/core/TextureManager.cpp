#include "core/TextureManager.h"

#include "utils/log.h"
#include "utils/assertion.h"

#include <utility>
#include <iterator>


void TextureManager::startup() {
    LOG_TRACE("Startup TextureManager");
    this->m_textures.clear();
}

void TextureManager::shutdown() {
    LOG_TRACE("Shutdown TextureManager");
    this->m_textures.clear();
}

Texture* TextureManager::createTexture(const char* name, const char* path) {
    auto elt = this->m_textures.emplace(std::make_pair(name, Texture{}));
    Texture* texture = &(elt.first->second);
    texture->loadFromFile(path);
    return texture;
}

Texture* TextureManager::getTextureByName(const char* name) {
    try {
        return &(this->m_textures.at(name));
    }
    catch (std::out_of_range& exception) {
        LOG_DEBUG("Texture '%s' doesn't exists in TextureManager", name);
        ASSERT_QUIT("Requested texture doesn't exists in TextureManager");
        return nullptr;
    }
}
