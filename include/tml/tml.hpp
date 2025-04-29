#pragma once

#if defined(_WIN32) || defined(__APPLE__)

    #define TML

#else

    #warning TML not tested on this platform. The library might not work as expected.

#endif

#include "cursor.hpp"