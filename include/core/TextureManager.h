#pragma once

#include "core/Texture.h"
#include "utils/Singleton.h"

#include <unordered_map>


/**
 * Manager all textures.
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
        std::unordered_map<char*, Texture> m_textures;

    private:
        TextureManager() = default;
        ~TextureManager() = default;

    public:
        void startup() override;
        void shutdown() override;

    private:
        //TODO
        //Texture& createTexture(const char* path);
        void createTexture(const char* name, const char* path);
        //Texture* getTextureByName(const char* name);
};

