#pragma once

#include "helper/Platform.h"
#include "helper/Singleton.h"
#include "Keyboard.h"
#include "KeyBinding.h"


/**
 * General Game input manager.
 */
class InputManager : private Singleton<InputManager> {
    private:
        friend Singleton<InputManager>;

    public:
        using Singleton<InputManager>::getInstance;

    public:
        Keyboard m_keyboard;
        KeyBinding m_keybinding;

    private:
        InputManager() = default;
        ~InputManager() = default;

    public:
        void startUp() override;
        void shutDown() override;

    public:
        void update();
        bool isKeyDown(const char* keyname);
};
