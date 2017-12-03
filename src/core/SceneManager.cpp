#include "core/SceneManager.h"

#include "core/TextureManager.h"
#include "utils/gameConfig.h"
#include "utils/log.h"

class Texture;

void SceneManager::startup() {
    LOG_CONFIG("Startup SceneManager");

    bool success = this->m_gameMap.loadFromFile(GAME_CONFIG_DEFAULT_GAME_MAP_PATH);
    if(!success) {
        LOG_ERROR("Unable to load the GameMap from path %s", GAME_CONFIG_DEFAULT_GAME_MAP_PATH);
        throw std::runtime_error("Unable to load GameMap from: " GAME_CONFIG_DEFAULT_GAME_MAP_PATH);
    }

    Texture* texture = TextureManager::getInstance().createTexture(TEXTURE_TILE_NAME, TEXTURE_TILE_PATH);
    if(texture == NULL) {
        LOG_ERROR("Unable to load the texture %s from path %s", TEXTURE_TILE_PATH);
        throw std::runtime_error("Unable to load a texture: " TEXTURE_TILE_PATH);
    }
}

void SceneManager::shutdown() {
}
