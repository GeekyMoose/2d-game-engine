#pragma once

#include "utils/Platform.h"

#include <cstdint>


/**
 *
 * \author  Constantin Masson
 * \date    Oct 2017
 */
class Keyboard {
    private:
        const std::uint8_t *m_state;

    public:
        Keyboard();
        ~Keyboard() = default;

    public:
        const std::uint8_t* getKeyboardState();
};
