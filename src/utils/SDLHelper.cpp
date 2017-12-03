#include "utils/SDLHelper.h"

#include "utils/log.h"

#if PLATFORM_WINDOWS
#   include <SDL.h>
#   include <SDL_image.h>
#elif PLATFORM_LINUX
#   include <SDL2/SDL.h>
#   include <SDL2/SDL_image.h>
#endif


SDL_Surface* SDLHelper::loadSurfaceFromFile(const char* file) {
    auto toto = IMG_Load(file);
    if(toto == NULL){
        LOG_ERROR("Unable to load Surface from file: %s", file);
        return nullptr;
    }
    return toto;
}

bool SDLHelper::drawOnSurface(SDL_Surface* src,
                              SDL_Surface* dest,
                              const int x,
                              const int y) {
    if(dest == NULL || src == NULL) {
        return false;
    }

    SDL_Rect rectDest;
    rectDest.x = x;
    rectDest.y = y;
    SDL_BlitSurface(src, NULL, dest, &rectDest);
    return true;
}

bool SDLHelper::drawOnSurface(SDL_Surface* src,
                              const int src_x,
                              const int src_y,
                              const int src_width,
                              const int src_height,
                              SDL_Surface* dest,
                              const int x,
                              const int y) {
    if(src == NULL || dest == NULL) {
        return false;
    }

    SDL_Rect srcRect;
    srcRect.x = src_x;
    srcRect.y = src_y;
    srcRect.w = src_width;
    srcRect.h = src_height;

    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;

    SDL_BlitSurface(src, &srcRect, dest, &destRect);
    return true;;
}

bool SDLHelper::applyTransparencyOnSurface(SDL_Surface* dest,
                                           const int red,
                                           const int green,
                                           const int blue) {
    if(dest == NULL){
        return false;
    }

    int val = SDL_SetColorKey(dest, SDL_TRUE, SDL_MapRGB(dest->format, red, green, blue));
    return (val == 0) ? true : false; //TODO: Returning val may be better?
}
