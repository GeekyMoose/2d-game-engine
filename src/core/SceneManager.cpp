#include "core/SceneManager.h"

#include "utils/gameConfig.h"
#include "utils/log.h"
#include "core/Sprite.h"
#include "core/TextureManager.h"
#include "core/SpriteManager.h"

class Texture;


void SceneManager::startup() {
    LOG_TRACE("Startup SceneManager");

    // TODO: For now, resource loading is hardcoded here
    Texture* texture = TextureManager::getInstance().createTexture(TEXTURE_TILE_NAME, TEXTURE_TILE_PATH);
    if(texture == NULL) {
        LOG_ERROR("Unable to load the texture %s from path %s", TEXTURE_TILE_PATH);
        throw std::runtime_error("Unable to load a texture: " TEXTURE_TILE_PATH);
    }
    Sprite* sprite = SpriteManager::getInstance().createSprite(SPRITE_TILE_NAME);
    sprite->setTexture(texture);
    sprite->setFramePosition(0,0);
    sprite->setFrameDimension(GRID_DEFAULT_X_UNIT_SIZE, GRID_DEFAULT_Y_UNIT_SIZE);

    bool success = this->m_tilemap.loadFromFile(GAME_CONFIG_DEFAULT_TILEMAP_PATH);
    if(!success) {
        LOG_ERROR("Unable to load the GameMap from path %s", GAME_CONFIG_DEFAULT_TILEMAP_PATH);
        throw std::runtime_error("Unable to load GameMap from: " GAME_CONFIG_DEFAULT_TILEMAP_PATH);
    }
}

void SceneManager::shutdown() {
    LOG_TRACE("Shutdown SceneManager");
}

void SceneManager::renderScene(SDL_Surface* dest) {
    this->m_tilemap.render(dest, &this->m_camera);
}
