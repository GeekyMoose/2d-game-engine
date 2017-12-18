#pragma once

#include <stdio.h>
#include <signal.h>


// -----------------------------------------------------------------------------
// ASSERTIONS (IF ENABLED)
// -----------------------------------------------------------------------------
#ifndef _NDEBUG


#define debugBreak() raise(SIGTRAP)

#define reportAssertFailure(exp, file, line) \
    fprintf(stderr, "[ASSERT] %s:%d: failure: ("#exp") should be true.\n", file, line)

// ASSERT_TRUE Macro
#define ASSERT_TRUE(expression) \
if (expression) {} \
else { \
    reportAssertFailure(expression, __FILE__, __LINE__); \
    debugBreak(); \
}

#define ASSERT_QUIT(msg) \
    fprintf(stderr, "[ASSERT] %s:%d: Quit with message: "#msg"\n", __FILE__, __LINE__); \
    debugBreak()

// -----------------------------------------------------------------------------
// ASSERTIONS (IF DISABLED)
// -----------------------------------------------------------------------------
#else
#   define ASSERT_TRUE(expression)
#   define ASSERT_QUIT(msg)
#endif


