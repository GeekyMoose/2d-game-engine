#include "core/RenderWindowSDL.h"

#include "utils/gameConfig.h"
#include "utils/log.h"

#include <stdexcept>


//------------------------------------------------------------------------------
// Initialization
//------------------------------------------------------------------------------

RenderWindowSDL::RenderWindowSDL() {
    this->m_window = SDL_CreateWindow(
        GAME_CONFIG_WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_DEFAULT_WIDTH,
        WINDOW_DEFAULT_HEIGHT,
        SDL_WINDOW_HIDDEN
    );

    if(this->m_window == NULL) {
        LOG_ERROR("Unable to create SDL Window: %s", SDL_GetError());
        throw std::runtime_error(SDL_GetError());
    }

    //Load SDL_Surface from the window
    this->m_surface = SDL_GetWindowSurface(this->m_window);
    if(this->m_surface == NULL) {
        LOG_ERROR("Unable to create SDL Surface: %s", SDL_GetError());
        throw std::runtime_error(SDL_GetError());
    }
    this->clear();
    this->update();
}

RenderWindowSDL::~RenderWindowSDL() {
    SDL_FreeSurface(this->m_surface);
    SDL_DestroyWindow(this->m_window);
}


//------------------------------------------------------------------------------
// Other methods
//------------------------------------------------------------------------------

void RenderWindowSDL::show() {
    SDL_ShowWindow(this->m_window);
}

void RenderWindowSDL::hide() {
    SDL_HideWindow(this->m_window);
}

void RenderWindowSDL::maximize() {
    SDL_MaximizeWindow(this->m_window);
}

void RenderWindowSDL::minimize() {
    SDL_MinimizeWindow(this->m_window);
}

void RenderWindowSDL::update() {
    SDL_UpdateWindowSurface(this->m_window);
}

void RenderWindowSDL::clear() {
    SDL_FillRect(this->m_surface, NULL, SDL_MapRGB(this->m_surface->format, 0x00, 0x00, 0x00));
}


//------------------------------------------------------------------------------
// SDL Specific methods
//------------------------------------------------------------------------------
SDL_Surface* RenderWindowSDL::getSurface() {
    return this->m_surface;
}

