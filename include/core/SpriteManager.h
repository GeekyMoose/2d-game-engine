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

        /** All loaded sprites. */
        std::unordered_map<char*, Sprite> m_sprites;

    public:
        using Singleton<SpriteManager>::getInstance;

    private:
        SpriteManager() = default;
        ~SpriteManager() = default;

    public:
        void startup() override;
        void shutdown() override;

    private:
        /*
         TODO
        Sprite& createSprite(const char* path);
        getSpriteByName(const char* name);
        */
};
