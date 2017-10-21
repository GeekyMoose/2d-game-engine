#pragma once

#include <iostream>

#define LOG_ERROR(msg) std::cout << "[ERROR]: " << msg << std::endl
#define LOG_WARNING(msg) std::cout << "[WARNING]: " << msg << std::endl
#define LOG_INFO(msg) std::cout << "[INFO]: " << msg << std::endl
#define LOG_DEBUG(msg) std::cout << "[DEBUG] [" << __FILE__ << ": " << __LINE__ << "]: " << msg << std::endl
