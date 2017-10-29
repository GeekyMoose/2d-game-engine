#include "input/KeyBinding.h"

void KeyBinding::registerKey(const char* name, const SDL_Scancode* key) {
    this->m_loopUpKeys.emplace(name, key);
}

SDL_Scancode* KeyBinding::lookUpKeyName(const char* name) {
    return this->m_loopUpKeys.at(name);
}
