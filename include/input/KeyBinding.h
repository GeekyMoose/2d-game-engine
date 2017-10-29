#pragma once

#include <unordered_map>

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


class KeyBinding {
    private:
        std::unordered_map<char*, SDL_Scancode> m_loopUpKeys;

    public:
        void registerKey(const char* name, const SDL_Scancode* key);
        SDL_Scancode& lookUpKeyName(const char* name);
};
