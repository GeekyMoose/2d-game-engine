#include "input/InputManager.h"

#include <cstdint>

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

void InputManager::startup() {
    // Bind all keys used for this game
    // TODO: May be extracted in external config file etc.
    this->m_inputKeybinder.registerKey("quit", SDL_SCANCODE_ESCAPE);
    this->m_inputKeybinder.registerKey("moveUp", SDL_SCANCODE_W);
    this->m_inputKeybinder.registerKey("moveDown", SDL_SCANCODE_S);
    this->m_inputKeybinder.registerKey("moveRight", SDL_SCANCODE_D);
    this->m_inputKeybinder.registerKey("moveLeft", SDL_SCANCODE_A);
}

void InputManager::shutdown() {
}

void InputManager::update() {
    SDL_PumpEvents();
}

bool InputManager::isKeyDown(const char* keyname) {
    const SDL_Scancode& keycode = this->m_inputKeybinder.lookUpKeyName(keyname);
    const std::uint8_t *state = this->m_keyboard.getKeyboardState();
    return static_cast<bool>(state[keycode]);
}
