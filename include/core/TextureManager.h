#pragma once

#include "utils/platform.h"
#include "utils/Singleton.h"
#include "core/Texture.h"

#include <unordered_map>


/**
 * Manager for all textures.
 *
 * \date    Dec 2017
 * \author  Constantin Masson
 */
class TextureManager : private Singleton<TextureManager> {
    private:
        friend Singleton<TextureManager>;
    public:
        using Singleton<TextureManager>::getInstance;

    private:
        /** All loaded Textures. */
        std::unordered_map<const char*, Texture> m_textures;

    private:
        TextureManager() = default;
        ~TextureManager() = default;

    public:
        void startup() override;
        void shutdown() override;

    public:
        /**
         * Create a new texture and register it in this manager.
         * if already a texture exists with this name,
         * old texture is reloaded with this new data.
         *
         * \param name Unique name of the texture.
         * \param path Path to the resource to load for this texture.
         * \return Pointer to the texture or nullptr if error.
         */
        Texture* createTexture(const char* name, const char* path);

        /**
         * Recover the texture registered at this name or nullptr if no texture.
         *
         * \param name The name of the texture to get.
         * \return Pointer to the texture or nullptr if none.
         */
        Texture* getTextureByName(const char* name);
};

