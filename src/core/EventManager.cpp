#include "core/EventManager.h"

#if PLATFORM_WINDOWS
#   include <SDL.h>
#elif PLATFORM_LINUX
#   include <SDL2/SDL.h>
#endif

void EventManager::onEvent(SDL_Event* sdlevent) {
    switch(sdlevent->type) {
        case SDL_KEYDOWN:
            onKeyDown(sdlevent->key.keysym);
            break;
        case SDL_KEYUP:
            onKeyUp(sdlevent->key.keysym);
            break;
        case SDL_QUIT:
            onExit();
            break;
        default:
            break;
    }
}
