#pragma once

#include "utils/Platform.h"

#if PLATFORM_WINDOWS
#   include <SDL.h>
#elif PLATFORM_LINUX
#   include <SDL2/SDL.h>
#endif


/**
 * Asset functions for SDL Surface Drawing.
 *
 * Abstract class (static functions only).
 */
class Surface final {

    private:
        Surface() = delete;
        ~Surface() = delete;


    public:

        /**
         * Load a SDL_Surface from a file.
         * Given file is an image that creates the surface.
         *
         * \param file  File to load (path + name + extension).
         * \return      The SDL_Surface or nullptr if failed.
         */
        static SDL_Surface* loadFromFile(const char* file);

        /**
         * Draw the whole source Surface into another Surface.
         *
         * \warning
         * Do nothing if any surface is NULL.
         *
         * \param src   Surface to draw.
         * \param dest  Surface where to draw.
         * \param x     X position where to place src in dest.
         * \param y     Y position where to place src in dest.
         * \return      True if successfully drawn, otherwise, return false.
         */
        static bool drawInSurface(SDL_Surface* src,
                                  SDL_Surface* dest,
                                  const int x,
                                  const int y);

        /**
         * Draw SDL_Surface on another SDL_Surface.
         *
         * \warning
         * Do nothing if any surface is NULL.
         *
         * \param src           Surface to draw.
         * \param src_x         Start at position x in source.
         * \param src_y         Start at position y in source.
         * \param src_width     Width to draw from source.
         * \param src_height    Height to draw from source.
         * \param dest          Surface where to draw.
         * \param x             X position where to place src in dest.
         * \param y             Y position where to place src in dest.
         * \return              True if successfully drawn, otherwise fase.
         */
        static bool drawInSurface(SDL_Surface* src,
                                  const int src_x,
                                  const int src_y,
                                  const int src_width,
                                  const int src_height,
                                  SDL_Surface* dest,
                                  const int x,
                                  const int y);

        /**
         * Set a color of a Surface as transparent.
         *
         * \param dest  Surface where to apply transparency.
         * \param r     Red value.
         * \param g     Green value.
         * \param b     Blue value.
         * \return      True if successfully applied, otherwise, return false.
         */
        static bool applyTransparency(SDL_Surface* dest, int r, int g, int b);
};

