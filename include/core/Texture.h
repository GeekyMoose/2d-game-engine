#pragma once

#include "utils/gameConfig.h"

class SDL_Surface;


/**
 * A texture component.
 *
 * \date    Dec 2017
 * \author  Constantin Masson
 */
class Texture {
    private:
        /** The actual texture data. */
        SDL_Surface* m_surface = nullptr;

        /** Unique name of the texture. */
        char m_name[TEXTURE_NAME_MAX_SIZE];

    public:
        /**
         * Create a new texture with specific name.
         * Name is truncated if length superior to max size (See config).
         * Name should be unique (No check done).
         *
         * \param name The identifier of this texture.
         */
        Texture(const char* name);

        /**
         * Destroys and release texture resources.
         */
        ~Texture();

    public:
        /**
         * Load a texture from a file.
         * If texture was already loaded, previous is freed before.
         *
         * \param path File to load (Full path + name + ext).
         * \return True if successfully loaded, otherwise, return false.
         */
        bool loadFromFile(const char* path);
};
