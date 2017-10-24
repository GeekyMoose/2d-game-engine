#include "sdl/Surface.h"

#include "helper/Logger.h"

#include <SDL2/SDL_image.h>


SDL_Surface* Surface::loadFromFile(const char* file) {
    auto toto = IMG_Load(file);
    if(toto == NULL){
        LOG_ERROR("Unable to load Surface from file");
        return nullptr;
    }
    return toto;
}

bool Surface::drawInSurface(SDL_Surface* src,
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

bool Surface::drawInSurface(SDL_Surface* src,
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

bool Surface::applyTransparency(SDL_Surface * dest, int r, int g, int b) {
    if(dest == NULL){
        return false;
    }

    int val = SDL_SetColorKey(dest, SDL_TRUE, SDL_MapRGB(dest->format, r, g, b));
    return (val == 0) ? true : false; //Note: Returning val could be better
}
