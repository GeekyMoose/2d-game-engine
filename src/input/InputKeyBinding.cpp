#include "input/InputKeyBinder.h"

void InputKeyBinder::registerKey(const char* name, SDL_Scancode key) {
    this->m_loopUpKeys.emplace(name, key);
}

SDL_Scancode& InputKeyBinder::lookUpKeyName(const char* name) {
    return this->m_loopUpKeys.at(name);
}
