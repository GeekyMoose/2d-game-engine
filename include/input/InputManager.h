#pragma once

#include "helper/Platform.h"
#include "helper/Singleton.h"
#include "Keyboard.h"
#include "InputKeyBinder.h"


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
        InputKeyBinder m_inputKeybinder;

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
