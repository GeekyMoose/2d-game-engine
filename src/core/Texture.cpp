#include "core/Texture.h"

#include "utils/log.h"
#include "utils/SDLHelper.h"

#if PLATFORM_WINDOWS
#   include <SDL.h>
#elif PLATFORM_LINUX
#   include <SDL2/SDL.h>
#endif


Texture::~Texture() {
    if(this->m_surface != nullptr) {
        SDL_FreeSurface(this->m_surface);
    }
}

bool Texture::loadFromFile(const char* path) {
    if(this->m_surface != nullptr) {
        SDL_FreeSurface(this->m_surface);
        this->m_surface = nullptr;
    }

    this->m_surface = SDLHelper::loadSurfaceFromFile(path);
    if(this->m_surface == nullptr) {
        LOG_ERROR("Unable to load the texture: %s", path);
        return false;
    }
    return true;
}

SDL_Surface* Texture::getSurface() const {
    return this->m_surface;
}
