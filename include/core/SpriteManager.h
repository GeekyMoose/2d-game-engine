#pragma once

#include "utils/Singleton.h"
#include "core/Sprite.h"

#include <unordered_map>


/**
 * Manager for all Sprite Resources.
 *
 * \date    Dec 2017
 * \author  Constantin Masson
 */
class SpriteManager : private Singleton<SpriteManager> {
    private:
        friend Singleton<SpriteManager>;
    public:
        using Singleton<SpriteManager>::getInstance;

    private:
        /** All loaded sprites. */
        std::unordered_map<const char*, Sprite> m_sprites;

    private:
        SpriteManager() = default;
        ~SpriteManager() = default;

    public:
        void startup() override;
        void shutdown() override;

    private:
        /**
         * Create a new sprite and register it in this manager.
         * if already a sprite exists with this name,
         * old sprite is reloaded with this new data.
         *
         * \param name Unique name of the sprite.
         * \return Pointer to the sprite or nullptr if error.
         */
        Sprite* createSprite(const char* name);

        /**
         * Recover the sprite registered at this name or nullptr if no sprite.
         *
         * \param name The name of the sprite to get.
         * \return Pointer to the sprite or nullptr if none.
         */
        Sprite* getSpriteByName(const char* name);
};



