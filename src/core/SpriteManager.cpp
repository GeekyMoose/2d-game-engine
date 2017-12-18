#include "core/SpriteManager.h"

#include "utils/log.h"
#include "utils/assertion.h"

#include <utility>
#include <iterator>
#include <signal.h>


void SpriteManager::startup() {
    LOG_TRACE("Startup SpriteManager");
    this->m_sprites.clear();
}

void SpriteManager::shutdown() {
    LOG_TRACE("Shutdown SpriteManager");
    this->m_sprites.clear();
}


Sprite* SpriteManager::createSprite(const char* name) {
    auto elt = this->m_sprites.emplace(std::make_pair(name, Sprite{}));
    Sprite* sprite = &(elt.first->second);
    return sprite;
}

Sprite* SpriteManager::getSpriteByName(const char* name) {
    try {
        return &(this->m_sprites.at(name));
    }
    catch (std::out_of_range& exception) {
        LOG_DEBUG("Sprite '%s' doesn't exists in SpriteManager", name);
        ASSERT_QUIT("Requested sprite doesn't exists in SpriteManager");
        return nullptr;
    }
}
