#pragma once


class SDL_Surface;
class RenderWindowSDL;


/**
 * RenderSystem with SDL implementation.
 *
 * \date    Dec 2017
 * \author  Constantin Masson
 */
class RenderSystemSDL {
    private:
        SDL_Surface* m_windowSurface = nullptr; // Surface of the window where to draw

    public:
        RenderSystemSDL() = default;
        ~RenderSystemSDL() = default;

    public:

        /**
         * Create a new window.
         * New window is allocated on the heap and should be manually deleted.
         *
         * \return Pointer to the newly created window.
         */
        RenderWindowSDL* newRenderWindow() const;

        /**
         * This RenderSystem will draw on this window.
         *
         * \param window RenderWindow where to draw.
         */
        void setRenderWindow(RenderWindowSDL& window);
};


