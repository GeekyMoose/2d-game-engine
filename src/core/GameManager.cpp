#include "core/GameManager.h"

void GameManager::startup() {
    this->m_gameMap.loadFromFile(GAME_CONFIG_DEFAULT_GAME_MAP_PATH);
}

void GameManager::shutdown() {
}

void GameManager::render() {
    //TODO this->m_gameMap.render();
}
