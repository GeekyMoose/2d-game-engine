#include "core/SceneManager.h"

void SceneManager::startup() {
    bool success = this->m_gameMap.loadFromFile(GAME_CONFIG_DEFAULT_GAME_MAP_PATH);
    if(!success) {
        throw "Unable to load GameMap"; // TODO tmp: Add better error msg etc
    }
}

void SceneManager::shutdown() {
}
