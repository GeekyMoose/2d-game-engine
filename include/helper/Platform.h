#pragma once

// Platform specific includes.

#if defined(_WIN32) || defined(_WIN64)
#   include "PlatformWindows.h"
#elif defined(linux)
#   include "PlatformLinux.h"
#endif
