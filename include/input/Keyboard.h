#pragma once

#include "utils/Platform.h"

#include <cstdint>


class Keyboard {
    private:
        const std::uint8_t *m_state;

    public:
        Keyboard();
        ~Keyboard() = default;

    public:
        const std::uint8_t* getKeyboardState();
};
