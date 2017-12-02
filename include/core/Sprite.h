#pragma once

#include <string>


/**
 * Sprite component.
 *
 * \date    Dev 2017
 * \author  Constantin Masson
 */
class Sprite {
    private:
        std::string m_path;

    private:
        int m_frameWidth;
        int m_frameHeight;
};
