#include "input/Keyboard.h"

#if PLATFORM_WINDOWS
#   include <SDL.h>
#   include <SDL_keyboard.h>
#   include <SDL_keycode.h>
#   include <SDL_scancode.h>
#elif PLATFORM_LINUX
#   include <SDL2/SDL.h>
#   include <SDL2/SDL_keyboard.h>
#   include <SDL2/SDL_keycode.h>
#   include <SDL2/SDL_scancode.h>
#endif


Keyboard::Keyboard() : m_state(SDL_GetKeyboardState(nullptr)) {
}

const std::uint8_t* Keyboard::getKeyboardState() {
    return this->m_state;
}
