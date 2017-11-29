#pragma once

#include "utils/Platform.h"

#include <unordered_map>
#include <string>

#if PLATFORM_WINDOWS
#   include <SDL.h>
#   include <SDL_keyboard.h>
#   include <SDL_keycode.h>
#   include <SDL_scancode.h>
#elif PLATFORM_LINUX
#   include "SDL2/SDL.h"
#   include "SDL2/SDL_keyboard.h"
#   include "SDL2/SDL_keycode.h"
#   include "SDL2/SDL_scancode.h"
#endif


/**
 *
 * \author  Constantin Masson
 * \date    Oct 2017
 */
class InputKeyBinder {
    private:
        std::unordered_map<std::string, SDL_Scancode> m_loopUpKeys;

    public:
        void registerKey(const char* name, SDL_Scancode key);
        SDL_Scancode& lookUpKeyName(const char* name);
};
