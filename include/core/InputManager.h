#pragma once

#include "helper/Platform.h"


class InputManager : private Singleton<InputManager> {
    private:
        friend Singleton<InputManager>;
    public:
        using Singleton<InputManager>::getInstance;
};
