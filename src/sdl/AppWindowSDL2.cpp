#include "sdl/AppWindowSDL2.h"
#include "helper/gameConfig.h"
#include "helper/Logger.h"


//------------------------------------------------------------------------------
// Initialization
//------------------------------------------------------------------------------
AppWindowSDL2::~AppWindowSDL2() {
    this->destroy();
}

void AppWindowSDL2::initialize() {
    this->m_SDLwindow = SDL_CreateWindow(
        GAME_CONFIG_WINDOW_TITLE,
        WINDOW_DEFAULT_POS_LEFT,
        WINDOW_DEFAULT_POS_RIGHT,
        WINDOW_DEFAULT_WIDTH,
        WINDOW_DEFAULT_HEIGHT,
        GAME_CONFIG_WINDOW_DEFAULT_MODE
    );

    if(this->m_SDLwindow == NULL) {
        LOG_ERROR(SDL_GetError());
        return;
    }

    //Load SDL_Surface from the window
    this->m_SDLsurface = SDL_GetWindowSurface(this->m_SDLwindow);
    SDL_FillRect(this->m_SDLsurface, NULL, SDL_MapRGB(this->m_SDLsurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(this->m_SDLwindow);
}

void AppWindowSDL2::destroy() {
    SDL_FreeSurface(this->m_SDLsurface);
    SDL_DestroyWindow(this->m_SDLwindow);
}


//------------------------------------------------------------------------------
// Other methods
//------------------------------------------------------------------------------

void AppWindowSDL2::show() {
    SDL_ShowWindow(this->m_SDLwindow);
}

void AppWindowSDL2::hide() {
    SDL_HideWindow(this->m_SDLwindow);
}

void AppWindowSDL2::maximize() {
    SDL_MaximizeWindow(this->m_SDLwindow);
}

void AppWindowSDL2::minimize() {
    SDL_MinimizeWindow(this->m_SDLwindow);
}


//------------------------------------------------------------------------------
// Getter / Setters
//------------------------------------------------------------------------------

SDL_Surface* AppWindowSDL2::getSurface() const {
    return this->m_SDLsurface;
}

SDL_Window* AppWindowSDL2::getRoot() const {
    return this->m_SDLwindow;
}
