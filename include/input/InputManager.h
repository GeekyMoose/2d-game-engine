#pragma once

#include "utils/Platform.h"
#include "utils/Singleton.h"
#include "Keyboard.h"
#include "InputKeyBinder.h"


/**
 * General Game input manager.
 *
 * \author  Constantin Masson
 * \date    Oct 2017
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
        void startup() override;
        void shutdown() override;

    public:
        void update();
        bool isKeyDown(const char* keyname);
};
