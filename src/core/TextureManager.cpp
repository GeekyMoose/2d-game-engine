#include "core/TextureManager.h"

#include <utility>

void TextureManager::startup() {
}

void TextureManager::shutdown() {
    // TODO: Free all resources
}

//Texture& TextureManager::createTexture(const char* name, const char* path) {
void TextureManager::createTexture(const char* name, const char* path) {
    //auto elt = this->m_textures.emplace(std::make_pair(name));
    //TODO
}

/*
Texture* TextureManager::getTextureByName(const char* name) {
    try {
        Texture& t = this->m_textures.at(name);
        //return texture;
        return NULL;
    }
    catch (std::out_of_range& exception) {
        return NULL;
    }
}
*/
