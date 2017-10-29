#include "input/InputManager.h"

#include <cstdint>

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

void InputManager::startUp() {
}

void InputManager::shutDown() {
}

void InputManager::update() {
    SDL_PumpEvents();
}

bool InputManager::isKeyDown(const char* keyname) {
    const SDL_Scancode& keycode = this->m_keybinding.lookUpKeyName(keyname);
    const std::uint8_t *state = this->m_keyboard.getKeyboardState();
    return static_cast<bool>(state[keycode]);
}
