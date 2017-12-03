#pragma once

#include "utils/platform.h"
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

    public:
        Texture() = default;
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
